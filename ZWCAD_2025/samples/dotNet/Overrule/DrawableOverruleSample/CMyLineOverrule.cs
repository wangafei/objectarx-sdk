using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.GraphicsInterface;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Geometry;
using ZwSoft.ZwCAD.Runtime;

namespace DrawableOverruleSample
{
    class CMyLineOverrule : DrawableOverrule
    {
        public CMyLineOverrule()
        {

        }

        public override bool WorldDraw(Drawable drawable, WorldDraw wd)
        {
            Line line = drawable as Line;
            if (line != null)
            {
                wd.SubEntityTraits.Color = 35;
                string msg = line.GetType().ToString();
                wd.Geometry.Text(line.EndPoint, Vector3d.ZAxis, Vector3d.XAxis, 10, 1, 0, msg);
            }
            return base.WorldDraw(drawable, wd);
        }

        public override bool IsApplicable(RXObject overruledSubject)
        {
            return true;
        }
    }
}
