/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCDMMAPI_H
#define _GCDMMAPI_H

#include "GdGChar.h"
#include "gcdmmeplotproperty.h"
#include "gcdmmeplotproperties.h"
#include "gcdmmutils.h"
#include "GcPlPlotLogger.h"
#include "Gc3dDwfNavTree.h"

class GcDMMSheetReactorInfo
{
public:
  enum PlotArea {
    kDisplay = 0,
    kExtents = 1,
    kLimits = 2,
    kView,
    kWindow,
    kLayout
  };

  enum PlotRotation {
    k0degrees,
    k90degrees,
    k180degrees,
    k270degrees
  };

  enum PlotMediaUnits {
    kInches,
    kMillimeters,
    kPixels
  };

  virtual GcPlPlotLogger * GetPlotLogger() = 0;

  virtual GcDbDatabase* database()      const = 0;

  virtual bool    isPlotJobCancelled()    const = 0;

  virtual void AddPageProperties(GcDMMEPlotPropertyVec props) = 0;
  virtual void AddPageResources(GcDMMResourceVec resources) = 0;

  virtual const GCHAR * UniqueLayoutId() = 0;
  virtual GcDbObjectId   plotLayoutId()           const = 0;
  virtual bool           isModelLayout()          const = 0;

  virtual PlotArea plotArea() const = 0;

  virtual PlotRotation plotRotation() const = 0;
  virtual PlotMediaUnits plotMediaUnits() const = 0;

  virtual double paperScale()                     const = 0;
  virtual double drawingScale()                   const = 0;

  virtual double originX()                        const = 0;
  virtual double originY()                        const = 0;

  virtual double plotWindowMinX()                 const = 0;
  virtual double plotWindowMinY()                 const = 0;
  virtual double plotWindowMaxX()                 const = 0;
  virtual double plotWindowMaxY()                 const = 0;

  virtual const TCHAR*  viewPlotted()             const = 0;

  virtual bool isScaleSpecified()                 const = 0;

  virtual bool areLinesHidden()                   const = 0;

  virtual bool arePlottingLineWeights()           const = 0;
  virtual bool areScalingLineWeights()            const = 0;

  virtual double displayMinX()                    const = 0;
  virtual double displayMinY()                    const = 0;
  virtual double displayMaxX()                    const = 0;
  virtual double displayMaxY()                    const = 0;

  virtual double layoutMarginMinX()               const = 0;
  virtual double layoutMarginMinY()               const = 0;
  virtual double layoutMarginMaxX()               const = 0;
  virtual double layoutMarginMaxY()               const = 0;

  virtual double printableBoundsX()               const = 0;
  virtual double printableBoundsY()               const = 0;

  virtual double maxBoundsX()                     const = 0;
  virtual double maxBoundsY()                     const = 0;

  virtual double stepsPerInch()                  const = 0;

  virtual const TCHAR* configuration()            const = 0;

  virtual const TCHAR* plotToFilePath()           const = 0;

  virtual const TCHAR* plotToFileName()           const = 0;
  virtual const TCHAR* canonicalMediaName()       const = 0;

  virtual double plotBoundsMinX()                 const = 0;
  virtual double plotBoundsMinY()                 const = 0;
  virtual double plotBoundsMaxX()                 const = 0;
  virtual double plotBoundsMaxY()                 const = 0;

  virtual double layoutBoundsMinX()               const = 0;
  virtual double layoutBoundsMinY()               const = 0;
  virtual double layoutBoundsMaxX()               const = 0;
  virtual double layoutBoundsMaxY()               const = 0;

  virtual double effectivePlotOffsetX()           const = 0;
  virtual double effectivePlotOffsetY()           const = 0;

  virtual int    effectivePlotOffsetXdevice()     const = 0;
  virtual int    effectivePlotOffsetYdevice()     const = 0;

  virtual bool    publishingTo3DDwf()     const = 0;

  virtual bool set3dDwfNavigationTreeNode(const Gc3dDwfNavTreeNode* root) = 0;
  virtual Gc3dDwfNavTreeNode* get3dDwfNavigationTreeNode() = 0;

public:
  virtual ~GcDMMSheetReactorInfo() {};

protected:
  GcDMMSheetReactorInfo() {};
};

class GcDMMEntityReactorInfo
{
public:

  virtual bool isCancelled()    const = 0;
  virtual const wchar_t * UniqueEntityId() = 0;
  virtual GcDbEntity* entity()             const = 0;
  virtual GcDbObjectId effectiveBlockLayerId()  const = 0;
  virtual bool GetCurrentEntityNode(GcDMMNode & node, GcDbObjectIdArray objIds) const = 0;
  virtual int GetNextAvailableNodeId() const = 0;
  virtual bool GetEntityNode(GcDbObjectId id, GcDbObjectIdArray objIds,
    int & nodeId) const = 0;
  virtual const GcDMMNode * GetNode(int nodeId) const = 0;
  virtual GcPlPlotLogger * GetPlotLogger() = 0;
  virtual bool SetCurrentNode(int nodeId, GcDbObjectIdArray objIds) = 0;
  virtual bool SetNodeName(int nodeNumber, const wchar_t *name) = 0;
  virtual bool AddProperties(const GcDMMEPlotProperties * props) = 0;
  virtual bool AddPropertiesIds(GcDMMStringVec * IdVec, GcDMMNode & node) = 0;
  virtual void flush() = 0;
  virtual void cancelTheJob() = 0;
  virtual bool AddNodeToMap(GcDbObjectId Id, GcDbObjectIdArray objIds, int nodeId) = 0;
  virtual bool add3DDwfProperty(const wchar_t *category, const wchar_t *name, const wchar_t *value) = 0;
  virtual bool add3DDwfAttribute(const wchar_t *category, const wchar_t *name,
    const wchar_t *ns, const wchar_t *nsUrl,
    const wchar_t *attName, const wchar_t *attVal) = 0;
  virtual const GcArray<long>& getGraphicIDs() = 0;
  virtual const GcDbObjectIdArray& getEntityBlockRefPath() = 0;

public:
  virtual ~GcDMMEntityReactorInfo() {};

protected:
  GcDMMEntityReactorInfo() {};
};

class GcDMMReactor : public GcRxObject
{
public:
  virtual void OnBeginSheet(GcDMMSheetReactorInfo * pInfo);
  virtual void OnBeginEntity(GcDMMEntityReactorInfo * pInfo);
  virtual void OnEndEntity(GcDMMEntityReactorInfo * pInfo);
  virtual void OnEndSheet(GcDMMSheetReactorInfo * pInfo);

  virtual ~GcDMMReactor() {};

protected:
  GcDMMReactor() {};
};

inline void GcDMMReactor::OnBeginSheet(GcDMMSheetReactorInfo * pInfo) {};
inline void GcDMMReactor::OnBeginEntity(GcDMMEntityReactorInfo * pInfo) {};
inline void GcDMMReactor::OnEndEntity(GcDMMEntityReactorInfo * pInfo) {};
inline void GcDMMReactor::OnEndSheet(GcDMMSheetReactorInfo * pInfo) {};

void GcGlobAddDMMReactor(GcDMMReactor * pReactor);

void GcGlobRemoveDMMReactor(GcDMMReactor * pReactor);

typedef void(__cdecl *GCGLOBADDDMMREACTOR)(GcDMMReactor * pReactor);
typedef void(__cdecl *GCGLOBREMOVEDMMREACTOR)(GcDMMReactor * pReactor);

#endif 