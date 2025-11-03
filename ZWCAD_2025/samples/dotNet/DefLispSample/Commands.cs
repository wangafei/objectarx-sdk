using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.Runtime;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;

[assembly: CommandClass(typeof(DefLispSample.Commands))]

namespace DefLispSample
{
    class Commands
    {
        [CommandMethod("HelloCS")]
        static public void HelloCS()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            ed.WriteMessage("\nHello World!");
        }

        // Input (rectarea (getpoint "\nPick first point:") (getpoint "\nPick corner point:")) or (rectarea '(0 0 0) '(100 100 0)) to call the lisp function.
        [LispFunction("RectArea")]
        static public void RectArea(ResultBuffer rbArgs)
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;

            if (rbArgs == null)
            {
                ed.WriteMessage("\nArgument is null!");
                return;
            }

            Point3d[] pt3dArr = new Point3d[2];
            TypedValue[] tvArr = rbArgs.AsArray();
            if (tvArr.Count() < 2)
            {
                ed.WriteMessage("\nMissing parameters!");
                return;
            }

            for (int i = 0; i < 2; i++)
            {
                TypedValue rb = tvArr[i];
                if (rb.TypeCode == (int)LispDataType.Point3d)
                {
                    pt3dArr[i] = (Point3d)rb.Value;
                }
                else if (rb.TypeCode == (int)LispDataType.Point2d)
                {
                    Point2d pt2dTmp = (Point2d)rb.Value;
                    pt3dArr[i] = new Point3d(pt2dTmp.X, pt2dTmp.Y, 0);
                }
                else
                {
                    ed.WriteMessage("\n{0} parameter should be 2D point or 3D point!", i == 0 ? "First" : "Second");
                    return;
                }
            }
            ed.WriteMessage("\nRectangPoint1({0},{1},{2}), RectangPoint2({3},{4},{5})", pt3dArr[0].X, pt3dArr[0].Y, pt3dArr[0].Z, pt3dArr[1].X, pt3dArr[1].Y, pt3dArr[1].Z);
            ed.WriteMessage("\nRectang Area: {0}", System.Math.Abs((pt3dArr[0].X - pt3dArr[1].X) * (pt3dArr[0].Y - pt3dArr[1].Y)));
        }
    }
}
