using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.Runtime;

namespace GeometryOverruleSample
{
    public class MyGeometryOverrule : GeometryOverrule
    {
        public override void IntersectWith(Entity entity, Entity ent, Intersect intType, Point3dCollection points, IntPtr thisGsMarker, IntPtr otherGsMarker)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\nMyGeometryOverrule::intersectWith()<pSubject: {0}>...", entity.GetType().Name);
            Point3dCollection tmpPoints = new Point3dCollection();

            if (entity.GetType() == typeof(Line))
            {
                Point3d pt1 = new Point3d(50, 50, 0), pt2 = new Point3d(100, 100, 0);
                points.Add(pt1);
                points.Add(pt2);
                ed.WriteMessage("\n<AcDbLine> Find {0} Points", points.Count);
            }
            else if (entity.GetType() == typeof(Circle))
            {
                Point3d pt = new Point3d(1, 1, 0);
                points.Add(pt);
                ed.WriteMessage("\n<AcDbCircle> Find {0} Points", points.Count);
            }
            else
            {
                Point3d pt = new Point3d(2, 2, 0);
                points.Add(pt);
                ed.WriteMessage("\n<OtherType> Find {0} Points", points.Count);
            }

            //base.IntersectWith(entity, ent, intType, points, thisGsMarker, otherGsMarker);
            base.IntersectWith(entity, ent, intType, tmpPoints, thisGsMarker, otherGsMarker);
        }

        public override void IntersectWith(Entity entity, Entity ent, Intersect intType, Plane projPlane, Point3dCollection points, IntPtr thisGsMarker, IntPtr otherGsMarker)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\nMyGeometryOverrule::intersectWith(Plane)<pSubject: {0}>...", entity.GetType().Name);
            Point3dCollection tmpPoints = new Point3dCollection();

            if (entity.GetType() == typeof(Line))
            {
                Point3d pt1 = new Point3d(50, 50, 0), pt2 = new Point3d(100, 100, 0);
                points.Add(pt1);
                points.Add(pt2);
                ed.WriteMessage("\n<AcDbLine> Find {0} Points", points.Count);
            }
            else if (entity.GetType() == typeof(Circle))
            {
                Point3d pt = new Point3d(1, 1, 0);
                points.Add(pt);
                ed.WriteMessage("\n<AcDbCircle> Find {0} Points", points.Count);
            }
            else
            {
                Point3d pt = new Point3d(2, 2, 0);
                points.Add(pt);
                ed.WriteMessage("\n<OtherType> Find {0} Points", points.Count);
            }

            //base.IntersectWith(entity, ent, intType, projPlane, points, thisGsMarker, otherGsMarker);
            base.IntersectWith(entity, ent, intType, projPlane, tmpPoints, thisGsMarker, otherGsMarker);
        }

        public override Extents3d GetGeomExtents(Entity entity)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            ed.WriteMessage("\nMyGeometryOverrule::getGeomExtents()<pSubject: {0}>...", entity.GetType().Name);
            Extents3d extents = new Extents3d();

            if (entity.GetType() == typeof(Line))
            {
                Point3d ptMax = new Point3d(100, 100, 0), ptMin = new Point3d(5, 5, 0);
                extents.AddPoint(ptMax);
                extents.AddPoint(ptMin);
                ed.WriteMessage("\nAcDbLine extents: ({0}, {1})-->({2}, {3})", ptMin.X, ptMin.Y, ptMax.X, ptMax.Y);

                return extents;
            }
            else if (entity.GetType() == typeof(Circle))
            {
                Point3d ptMax = new Point3d(50, 50, 0), ptMin = new Point3d(0, 0, 0);
                extents.AddPoint(ptMax);
                extents.AddPoint(ptMin);
                ed.WriteMessage("\nAcDbCircle extents: ({0}, {1})-->({2}, {3})", ptMin.X, ptMin.Y, ptMax.X, ptMax.Y);

                return extents;
            }
            else
            {
                Point3d ptMax = new Point3d(20, 20, 0), ptMin = new Point3d(0, 0, 0);
                extents.AddPoint(ptMax);
                extents.AddPoint(ptMin);
                ed.WriteMessage("\nOtherType extents: ({0}, {1})-->({2}, {3})", ptMin.X, ptMin.Y, ptMax.X, ptMax.Y);

                return extents;
            }

            //return base.GetGeomExtents(entity);
        }

        public override bool IsApplicable(RXObject overruledSubject)
        {
            return true;
        }

    }
}
