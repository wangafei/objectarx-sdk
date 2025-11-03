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

[assembly: CommandClass(typeof(DrawableOverruleSample.Commands))]

namespace DrawableOverruleSample
{
    class Commands
    {
        static CMyLineOverrule drawableOverride;
        [CommandMethod("AddDrawableOverrule")] 
        static public void AddDrawableOverrule()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                try
                {
                    if (drawableOverride == null)
                    {
                        drawableOverride = new CMyLineOverrule();
                        Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), drawableOverride, false);
                        drawableOverride.SetCustomFilter();
                    }
                    Overrule.Overruling = true;
                    Application.DocumentManager.MdiActiveDocument.Editor.Regen();
                }
                catch (System.Exception ex)
                {
                    ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
                }

                trans.Commit();
            }
        }

        [CommandMethod("RemoveDrawableOverrule")]
        static public void RemoveDrawableOverrule()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                try
                {
                    if (drawableOverride != null)
                    {
                        Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), drawableOverride);
                        drawableOverride = null;
                    }
                    Overrule.Overruling = false;
                    Application.DocumentManager.MdiActiveDocument.Editor.Regen();
                }
                catch (System.Exception ex)
                {
                    ed.WriteMessage(ex.Message + " " + ex.StackTrace + "\n");
                }

                trans.Commit();
            }
        }
    }
}
