using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.Runtime;

namespace GripOverruleSample
{
    class CMyGripOverrule : GripOverrule
    {
        public CMyGripOverrule()
        {

        }

        public override void GetGripPoints(Entity entity, GripDataCollection grips, double curViewUnitSize, int gripSize, Vector3d curViewDir, GetGripPointsFlags bitFlags)
        {
            if (IsApplicable(entity))
            {
                Line line = entity as Line;
                if (line != null)
                {
                    double len = line.StartPoint.DistanceTo(line.EndPoint);
                    if (len < 1000)
                    {
                        base.GetGripPoints(entity, grips, curViewUnitSize, gripSize, curViewDir, bitFlags);
                        grips.Clear();
                        return;
                    }
                }
            }
            base.GetGripPoints(entity, grips, curViewUnitSize, gripSize, curViewDir, bitFlags);
        }
        public override void GetGripPoints(Entity entity, Point3dCollection gripPoints, IntegerCollection snapModes, IntegerCollection geometryIds)
        {
            if (IsApplicable(entity))
            {
                Line line = entity as Line;
                if (line != null)
                {
                    double len = line.StartPoint.DistanceTo(line.EndPoint);
                    if (len < 1000)
                    {
                        base.GetGripPoints(entity, gripPoints, snapModes, geometryIds);
                        gripPoints.Clear();
                        return;
                    }
                }
            }
            base.GetGripPoints(entity, gripPoints, snapModes, geometryIds);
        }
        public override void GetStretchPoints(Entity entity, Point3dCollection stretchPoints)
        {
            if (IsApplicable(entity))
            {
                Line line = entity as Line;
                if (line != null)
                {
                    double len = line.StartPoint.DistanceTo(line.EndPoint);
                    if (len < 1000)
                    {
                        base.GetStretchPoints(entity, stretchPoints);
                        stretchPoints.Clear();
                        return;
                    }
                }
            }
            base.GetStretchPoints(entity, stretchPoints);
        }
        public override void MoveGripPointsAt(Entity entity, GripDataCollection grips, Vector3d offset, MoveGripPointsFlags bitFlags)
        {
            if (IsApplicable(entity))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                ed.WriteMessage("\noffset vector ({0}, {1}, {2})", offset.X, offset.Y, offset.Z);
            }
            base.MoveGripPointsAt(entity, grips, offset, bitFlags);
        }
        public override void MoveGripPointsAt(Entity entity, IntegerCollection indices, Vector3d offset)
        {
            if (IsApplicable(entity))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                ed.WriteMessage("\noffset vector ({0}, {1}, {2})", offset.X, offset.Y, offset.Z);
            }
            base.MoveGripPointsAt(entity, indices, offset);
        }
        public override void MoveStretchPointsAt(Entity entity, IntegerCollection indices, Vector3d offset)
        {
            if (IsApplicable(entity))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                ed.WriteMessage("\noffset vector ({0}, {1}, {2})", offset.X, offset.Y, offset.Z);
            }
            base.MoveStretchPointsAt(entity, indices, offset);
        }
        public override void OnGripStatusChanged(Entity entity, GripStatus status)
        {
            if (IsApplicable(entity))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                if (status == GripStatus.DimDataToBeDeleted)
                {
                    ed.WriteMessage("\ndim data to be deleted");
                }
                else if (status == GripStatus.GripsDone)
                {
                    ed.WriteMessage("\ngrip done");
                }
                else if (status == GripStatus.GripsToBeDeleted)
                {
                    ed.WriteMessage("\ngrip has deleted");
                }
            }
            base.OnGripStatusChanged(entity, status);
        }
        public override bool IsApplicable(RXObject overruledSubject)
        {
            return overruledSubject.GetType() == typeof(Line);
        }
    }
}
