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

[assembly: CommandClass(typeof(ObjOverrule.Commands))]

namespace ObjOverrule
{
    class Commands
    {
        static CPolyLineOverrule polyLineOverrule = null;
        [CommandMethod("RemoveObjectOverrule")]
        static public void RemoveAcdbObjectOverrule()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            try
            {
                if (polyLineOverrule != null)
                {
                    Overrule.RemoveOverrule(RXObject.GetClass(typeof(Polyline)), polyLineOverrule);
                    polyLineOverrule = null;
                }
                Overrule.Overruling = false;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }

        [CommandMethod("AddObjectOverruleCanCopy")]
        static public void AddAcdbObjectOverruleCanCopy()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            RemoveAcdbObjectOverrule();

            try
            {
                if (polyLineOverrule == null)
                {
                    polyLineOverrule = new CPolyLineOverrule(true);
                    Overrule.AddOverrule(RXObject.GetClass(typeof(Polyline)), polyLineOverrule, false);
                    polyLineOverrule.SetCustomFilter();
                }
                Overrule.Overruling = true;
            }
            catch (System.Exception ex)
            {
                ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
            }
        }

        [CommandMethod("AddObjectOverruleCanNotCopy")]
        static public void AddAcdbObjectOverruleCanNotCopy()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            RemoveAcdbObjectOverrule();

            try
            {
                if (polyLineOverrule == null)
                {
                    polyLineOverrule = new CPolyLineOverrule(false);
                    Overrule.AddOverrule(RXObject.GetClass(typeof(Polyline)), polyLineOverrule, false);
                    polyLineOverrule.SetCustomFilter();
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
