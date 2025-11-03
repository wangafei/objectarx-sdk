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

[assembly: CommandClass(typeof(PropertiesOverruleSample.Commands))]

namespace PropertiesOverruleSample
{
    class Commands
    {
        static CPropertiesOverrule propertiesOverrule = null;
        [CommandMethod("RemovePropertiesOverrule")]
        static public void RemovePropertiesOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            try
            {
                if (propertiesOverrule != null)
                {
                    Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), propertiesOverrule);
                    propertiesOverrule = null;
                }
                Overrule.Overruling = false;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }

        [CommandMethod("AddPropertiesOverrule")]
        static public void AddPropertiesOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            try
            {
                if (propertiesOverrule == null)
                {
                    propertiesOverrule = new CPropertiesOverrule();
                    Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), propertiesOverrule, false);
                    propertiesOverrule.SetCustomFilter();
                }
                Overrule.Overruling = true;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }
    }
}
