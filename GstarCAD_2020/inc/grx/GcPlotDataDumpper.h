/*****************************************************************************
***     文件名: GcPlotDataDumpper.h
*****************************************************************************/

#ifndef __GCAD__PLOT_DUMPPER__INTERFACE__H__
#define __GCAD__PLOT_DUMPPER__INTERFACE__H__

#pragma once
class OdGsView;
class OdGiCommonDraw;
class OdCmEntityColor;


enum PlotGenResult
{
  //要继续简化
  eContinueSimplification = 0x1,
  //放弃REGN
  eAbortSimplification = 0x2,
  //数据已正确打印输出
  ePlotOk = 0x0
};

enum PlotGenSupportType
{
  plNothing   = 0,      // 仅支持直线和三角填充 

  plFillPath  = 0x0001, // 路径填充支持，若不支持，则填充对象进行三角剖分(内存大速度慢)
  plCircle    = 0x0002, // 支持圆
  plCircleArc = 0x0004, // 支持圆弧
  plEllipArc  = 0x0008, // 支持椭圆/椭圆弧
  plNurbs     = 0x0010, // 支持Nurbs
  plPlineCW   = 0x0020, // 固定线宽的PLine(优化图元，节省内存，加快性能)
  plRasterExt = 0x0040, // 支持光栅图像内部转换(即处理透明，亮度，对比度，褪色)

  plGdiText   = 0x0100, // GDI 文字支持
  plGdiDraw   = 0x0200, // 支持 GDI 绘制，绘制(OLE,WMF)
  plGradient  = 0x0400, // 支持渐变填充

  plUseDeviation = 0x1000,     // 自定义精度，回调deviation()，若不支持，则通过DPI计算

  plDefault      = plFillPath, // 默认支持样式
  plSupportAll   = 0xFFFF      // 全部扩展支持
};


class GcPlotDataDumpper
{
public:
  virtual ~GcPlotDataDumpper(void) {}

public:
  enum 
  {
    Maximal_Simplification,
    Minimal_Simplification
  };
  virtual void setDumpLevel(int dumpLevel) = 0;
  virtual int dumpLevel() const = 0;

public: // query
  // dpi (控制精度)
  virtual double dot_per_inch() const = 0;
  virtual double dot_per_mm() const = 0;

  // 实际打印区域大小，小于或等于页面大小 (涉及裁剪)
  virtual void plot_size_inch(OdGePoint2d& sz) const = 0;
  virtual void plot_size_mm(OdGePoint2d& sz) const = 0;
  virtual double logic_per_pixel() const = 0;
  // 背景色 (RGB)
  virtual COLORREF backgroundColor() const = 0;

  // 变换矩阵(DCS->PCS)，目前忽略
  // 本矩阵和(setViewportCenter, setViewportField)相关
  virtual OdGeMatrix3d plotMatrix() const = 0;

  // 支持类型
  virtual OdUInt32 supportTypes() const = 0;

  // 曲线精度
  virtual double deviation(const OdGiDeviationType dtype) const = 0;

  // 视口中心点(DCS)
  virtual void setViewportCenter(const OdGePoint2d& centerOffset) = 0;
  // 视口观察范围(DCS)
  virtual void setViewportField(double fieldWidth, double fieldHeight) = 0;

  // 视口裁剪区域（仅图纸空间）
  // numPolygons=1, pointCounts[0]=2 时为矩形裁剪区域(points[0]左下 points[1]右上)
  // 其他情况为非矩形裁剪区域，类似 PolyPolygon 处理
  virtual DWORD_PTR pushViewportClip(const OdGePoint2d* points,
    const int *pointCounts,
    int numPolygons) = 0;
  virtual void popViewportClip(DWORD_PTR status) = 0;

  //压入一个模型矩阵，目前忽略
  virtual void push_model_matrix(const OdGeMatrix2d &model) = 0;
  //弹出一个模型矩阵列，目前忽略
  virtual void pop_model_matrix(const OdGeMatrix2d &model) = 0;

public: // event
  //返回TRUE，表示打印取消
  virtual bool regenAbort() const = 0;

  // 初始化打印
  virtual void beginPlot() = 0;
  // 结束打印
  virtual void endPlot(bool bAborted = false) = 0;

  // 开始视图
  virtual void beginView(OdGsView* pView, const OdGeMatrix3d *xVport2Overall = NULL) = 0;
  // 结束视图
  virtual void endView(OdGsView* pView) = 0;

  // 开始打印实体前调用，返回false时，此实体不必输出
  virtual bool beginDrawable(const OdGiDrawable *pDrawable) = 0;
  // 结束一个实体的输出
  virtual void endDrawable(const OdGiDrawable *pDrawable) = 0;

public: // attribs setting
  // 根据 backgroundColor(), 设置当前调色板
  virtual void loadLogicalPalette(COLORREF* pPalette, OdUInt16 nColors) = 0;

#if defined(PROCESS_TRAITS) && 0 // 不解析特征
  // 设置当前绘制颜色
  // 需要检验 ColorMethod，识别前景色，背景色，索引色(pPalette[index])，真彩色
  virtual void setDrawColor(const OdCmEntityColor& color) = 0;
  // 设置当前绘制颜色(RGB)
  virtual void setDrawColor(COLORREF color) = 0;
  
  // 设置线宽 (索引值)
  virtual void setLineWeight(OdDb::LineWeight weight) = 0;

  // 填充模式 (是否填充)
  virtual void setFillMode(OdGiFillType fillMode) = 0;

  // 设置实体打印样式名称(Null => default plot style(normal))
  virtual void setPlotStyleName(const OdDbObjectId& plotStyleNameId = GcDbObjectId::kNull) = 0;
#endif

  virtual void onTraitsChanged(const OdGiSubEntityTraitsData& currTraits) = 0;
  virtual void onSwitchPlotStyleTranslation(bool bTrans) = 0;

public:
  //virtual void pushViewportClip(const OdGsDCPoint* points, const int *pointCounts, int numPolygons);
  //virtual void pushViewportClip(const OdGsDCPoint& min, const OdGsDCPoint& max);
  //virtual void popViewportClip();

public: // 基本图元输出

  virtual void polylineOut(OdInt32 numPoints, 
    const OdGePoint3d* vertexList) = 0;

  virtual void polygonOut(OdInt32 numPoints, 
    const OdGePoint3d* vertexList, 
    const OdGeVector3d* pNormal = 0) = 0;

  // 扩展接口
  virtual PlotGenResult polylineOut(OdInt32 numPoints, 
    const OdInt32* vertexIndexList,
    const OdGePoint3d* vertexList) = 0;

  virtual PlotGenResult triangleOut(const OdInt32* vertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0) = 0;

public: // 普通图元

  virtual PlotGenResult polylineProc(OdInt32 numPoints, 
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult polygonProc(OdInt32 nbPoints, 
    const OdGePoint3d* pVertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circleProc(const OdGePoint3d& center, 
    double radius, 
    const OdGeVector3d& normal, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circleProc(const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& thirdPoint, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circularArcProc(const OdGePoint3d& center,
    double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    double sweepAngle,
    OdGiArcType arcType = kOdGiArcSimple, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult circularArcProc(const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    OdGiArcType arcType = kOdGiArcSimple, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  // return eContinueSimplification: convert to polylineOut polygonOut
  virtual PlotGenResult ellipArcProc(const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointsOverrides,
    OdGiArcType arcType = kOdGiArcSimple, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult nurbsProc(const OdGeNurbCurve3d& nurbs) = 0;

  virtual PlotGenResult xlineProc(const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint) = 0;

  virtual PlotGenResult rayProc(const OdGePoint3d& basePoint,
    const OdGePoint3d& throughPoint) = 0;

  // new
  virtual PlotGenResult polyPointsProc(OdUInt32 numPoints,
    const OdGePoint3d* vertexList) = 0;

  virtual PlotGenResult plineConstWidthProc(OdUInt32 numPoints, 
    const OdGePoint3d* vertexList,
    double consWidth,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual PlotGenResult meshProc(OdInt32 rows,
    OdInt32 columns,
    const OdGePoint3d* pVertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) = 0;

  virtual PlotGenResult shellProc(OdInt32 numVertices,
    const OdGePoint3d* vertexList,
    OdInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) = 0;

  // 2 font text(SHX, TTF), test pTextStyle->isShxFont()
  // SHX: return eContinueSimplification
  // TTF: return eContinueSimplification, then try-output by follow order
  //      ttfTextProc(GDI文字), ttfPolyDrawProc(文字轮廓), shellProc(三角剖分)
  virtual PlotGenResult textProc(const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 length, 
    bool raw, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0) = 0;

  // GDI text: ExtTextOut(...)
  // return eContinueSimplification: continue try ttfPolyDrawProc()
  virtual PlotGenResult ttfTextProc(const OdGePoint3d& base,
    const OdGeVector3d& u, // direction
    const OdGeVector3d& v,
    double width, // width of all chars
    double height,
    const LOGFONT& lf, // to recompute lfHeight by height, lfEscapement&lfOrientation by u
    const OdChar* text,
    OdInt32 length, 
    const double* pCellX) = 0;

  // GDI contour: BeginPath EndPath FillPath
  // return eContinueSimplification: continue try shellProc()
  virtual PlotGenResult ttfPolyDrawProc(OdInt32 nbVertex, 
    const OdGePoint3d* pVertexList,
    OdInt32 faceListSize, 
    const OdInt32* pFaceList,
    const OdUInt8* pBezierTypes, 
    const OdGiFaceData* pFaceData = 0) = 0;

  // SHAPE: MUST return eContinueSimplification
  virtual PlotGenResult shapeProc(const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0) = 0;

  // all images, or converted from OLE, EMF, GradientFill, shade output(3d)
  // return eContinueSimplification: discarded
  virtual PlotGenResult rasterImageProc(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage,
    const OdGePoint2d* uvBoundary, // may not be null
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0) = 0;

  // EMF(WMF)
  // return eContinueSimplification: convert to raster image
  virtual PlotGenResult metafileDc(const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false) = 0;

  // OLE, or other OdGiSelfGdiDrawable(such as GradientFill, EMF, ...)
  // return eContinueSimplification: convert to raster image
  virtual PlotGenResult ownerDrawDc(const OdGiCommonDraw& toDraw,
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiSelfGdiDrawable* pDrawable,
    bool dcAligned = true,
    bool allowClipping = false) = 0;

  // GradientFill
  // return eContinueSimplification: convert to raster image
  virtual PlotGenResult gradientFillProc(OdInt32 nVertex,
    const OdGePoint3d* pVertexes,  // size==nVertex
    const OdCmEntityColor* pVertexColors,  // size==nVertex
    OdInt32 nTriangle,
    const OdInt32* pTriangles) = 0; //size==nTriangle*3
};

// 打印进度条处理
class GcPlotProgressMeter
{
public:
  virtual void start() = 0;

  virtual void stop() = 0;

  virtual void step(int nAdvance = 1) = 0;

  virtual void setLimit(int max) = 0;
};

#endif //__GCAD__PLOT_DUMPPER__INTERFACE__H__

