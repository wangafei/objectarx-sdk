using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.Runtime;

namespace TransformOverruleSample
{
    class CTransformOverrule : TransformOverrule
    {
        public override bool CloneMeForDragging(Entity entity)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nCTransformOverrule.CloneMeForDragging is called!");
            if (IsApplicable(entity))
            {
                Polyline pLine = entity as Polyline;
                if (pLine.StartPoint.DistanceTo(pLine.EndPoint) < 1000)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            return base.CloneMeForDragging(entity);
        }
        public override void Explode(Entity entity, DBObjectCollection entitySet)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nCTransformOverrule.Explode is called!");

            if (IsApplicable(entity))
            {
                Polyline pLine = entity as Polyline;
                Solid3d solid = new Solid3d();
                double len = pLine.StartPoint.DistanceTo(pLine.EndPoint);
                solid.CreateFrustum(len, 10, 10, 10);

                Matrix3d mat = new Matrix3d();
                Vector3d vec = new Vector3d(1, -(pLine.EndPoint.X - pLine.StartPoint.X) / (pLine.EndPoint.Y - pLine.StartPoint.Y), 0);
                mat = Matrix3d.Rotation(3.14 / 2, vec, Point3d.Origin);
                solid.TransformBy(mat);

                vec = new Vector3d((pLine.EndPoint.X + pLine.StartPoint.X) / 2.0, (pLine.EndPoint.Y + pLine.StartPoint.Y) / 2.0, 0);
                mat = Matrix3d.Displacement(vec);
                solid.TransformBy(mat);

                entitySet.Add(solid);
                return;
            }
            base.Explode(entity, entitySet);
        }

        public override Entity GetTransformedCopy(Entity entity, Matrix3d transform)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nCTransformOverrule.GetTransformedCopy is called!");
            if (IsApplicable(entity))
            {
                Matrix3d new_xform;
                Vector3d vec = new Vector3d(100, 100, 0);
                new_xform = Matrix3d.Displacement(vec);
                return base.GetTransformedCopy(entity, new_xform);
            }
            return base.GetTransformedCopy(entity, transform);
        }

        public override bool HideMeForDragging(Entity entity)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nCTransformOverrule.HideMeForDragging is called!");
            if (IsApplicable(entity))
            {
                Polyline pLine = entity as Polyline;
                if (pLine.StartPoint.DistanceTo(pLine.EndPoint) < 1000)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            return base.HideMeForDragging(entity);
        }

        public override void TransformBy(Entity entity, Matrix3d transform)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nCTransformOverrule.TransformBy is called!");
            if (IsApplicable(entity))
            {
                Matrix3d new_xform;
                Vector3d vec = new Vector3d(0, 0, 0);
                new_xform = Matrix3d.Displacement(vec);
                base.TransformBy(entity, new_xform);
                return;
            }
            base.TransformBy(entity, transform);
        }

        public override bool IsApplicable(RXObject overruledSubject)
        {
            if (overruledSubject.GetType() != typeof(Polyline))
            {
                return false;
            }
            if (((Polyline)overruledSubject).XData != null)
            {
                return false;
            }
            return true;
        }
    }
}
