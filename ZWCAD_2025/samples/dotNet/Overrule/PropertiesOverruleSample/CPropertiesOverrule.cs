using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Runtime;

namespace PropertiesOverruleSample
{
    class CPropertiesOverrule : PropertiesOverrule
    {
        public override Guid GetClassID(DBObject entity)
        {
            return base.GetClassID(entity);
        }
        public override void List(Entity entity)
        {
            if (IsApplicable(entity))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                ed.WriteMessage("\n CPropertiesOverrule list begin----");
                base.List(entity);
                ed.WriteMessage("\n CPropertiesOverrule list end----");
            }
            else
            {
                base.List(entity);
            }
        }
        public override bool IsApplicable(RXObject overruledSubject)
        {
            return overruledSubject.GetType() == typeof(Line);
        }
    }
}
