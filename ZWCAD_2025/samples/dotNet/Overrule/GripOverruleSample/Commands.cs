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

[assembly: CommandClass(typeof(GripOverruleSample.Commands))]

namespace GripOverruleSample
{
    class Commands
    {
        static CMyGripOverrule gripOverrule = null;
        [CommandMethod("AddGripOverrule")]
        static public void AddAcDbGripOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            try
            {
                if (gripOverrule == null)
                {
                    gripOverrule = new CMyGripOverrule();
                    Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), gripOverrule, false);
                    gripOverrule.SetCustomFilter();
                }
                Overrule.Overruling = true;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }

        [CommandMethod("RemoveGripOverrule")]
        static public void RemoveAcDbGripOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            try
            {
                if (gripOverrule != null)
                {
                    Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), gripOverrule);
                    gripOverrule = null;
                }
                Overrule.Overruling = false;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }
    }
}
