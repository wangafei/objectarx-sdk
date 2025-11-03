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

[assembly: CommandClass(typeof(TransformOverruleSample.Commands))]

namespace TransformOverruleSample
{
    class Commands
    {
        static CTransformOverrule transformOverrule = null;
        [CommandMethod("RemoveTransformOverrule")]
        static public void RemoveTransformOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            try
            {
                if (transformOverrule != null)
                {
                    Overrule.RemoveOverrule(RXObject.GetClass(typeof(Polyline)), transformOverrule);
                    transformOverrule = null;
                }
                Overrule.Overruling = false;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }

        [CommandMethod("AddTransformOverrule")]
        static public void AddTransformOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            try
            {
                if (transformOverrule == null)
                {
                    transformOverrule = new CTransformOverrule();
                    Overrule.AddOverrule(RXObject.GetClass(typeof(Polyline)), transformOverrule, false);
                    transformOverrule.SetCustomFilter();
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
