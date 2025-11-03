using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;
using ZwSoft.ZwCAD.Geometry;

namespace CircleJig
{
    class CDrawCircleJig : EntityJig
    {
        Point3d m_centerPoint;
        Vector3d m_normal;
        double m_dRadius;
        int m_iPromptCount;

        public CDrawCircleJig(Vector3d vec) : base(new Circle())
        {
            m_centerPoint = new Point3d(0, 0, 0);
            m_dRadius = 0.0;
            m_normal = vec;
            m_iPromptCount = 0;
        }

        protected override SamplerStatus Sampler(JigPrompts prompts)
        {
            JigPromptPointOptions jigOpts = new JigPromptPointOptions();
            jigOpts.UserInputControls = (UserInputControls.Accept3dCoordinates | UserInputControls.NoZeroResponseAccepted | UserInputControls.NoNegativeResponseAccepted);

            if (m_iPromptCount == 0)
            {
                jigOpts.Message = "\nPlease enter the center";
                PromptPointResult pres = prompts.AcquirePoint(jigOpts);

                if (pres.Status == PromptStatus.Cancel)
                {
                    return SamplerStatus.Cancel;
                }
                else
                {
                    Point3d centerPtTemp = pres.Value;
                    if (centerPtTemp != m_centerPoint)
                    {
                        m_centerPoint = centerPtTemp;
                        return SamplerStatus.OK;
                    }
                    else
                    {
                        return SamplerStatus.NoChange;
                    }
                }

            }
            else if (m_iPromptCount == 1)
            {
                jigOpts.Message = "\nPlease enter the radius";
                PromptPointResult pres = prompts.AcquirePoint(jigOpts);
                double radiusTemp = -1;
                Point3d acquiredPoint;
                acquiredPoint = pres.Value;
                radiusTemp = m_centerPoint.DistanceTo(acquiredPoint);

                if (pres.Status == PromptStatus.Cancel)
                {
                    return SamplerStatus.Cancel;
                }
                else
                {
                    if (radiusTemp != m_dRadius)
                    {
                        m_dRadius = radiusTemp;
                        return SamplerStatus.OK;
                    }
                    else
                    {
                        return SamplerStatus.NoChange;
                    }
                }
            }
            else
            {
                return SamplerStatus.NoChange;
            }

        }

        protected override bool Update()
        {
            switch (m_iPromptCount)
            {
                case 0:
                    ((Circle)Entity).Center = m_centerPoint;
                    ((Circle)Entity).Radius = m_dRadius;
                    break;
                case 1:
                    ((Circle)Entity).Radius = m_dRadius;
                    break;
                default:
                    break;
            }

            return true;
        }

        public void setPromptCount(int i)
        {
            m_iPromptCount = i;
        }

        public Entity GetEntity()
        {
            return Entity;
        }
    }
}
