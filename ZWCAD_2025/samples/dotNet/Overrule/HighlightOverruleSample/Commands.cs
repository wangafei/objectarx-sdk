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

[assembly: CommandClass(typeof(HighlightOverruleSample.Commands))]

namespace HighlightOverruleSample
{
    public class MyHighlightOverrule : HighlightOverrule
    {
        public override void Highlight(Entity entity, FullSubentityPath subId, bool highlightAll)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (IsApplicable(entity))
            {
                if (entity.GetType() == typeof(Line))
                {
                    ed.WriteMessage("\nAcDbLine highlight invalid...");
                    return;
                }
                else if (entity.GetType() == typeof(Circle))
                {
                    ed.WriteMessage("\nAcDbCircle highlight...");
                }
            }

            base.Highlight(entity, subId, highlightAll);
        }

        public override void Unhighlight(Entity entity, FullSubentityPath subId, bool highlightAll)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (IsApplicable(entity))
            {
                if (entity.GetType() == typeof(Line))
                {
                    ed.WriteMessage("\nAcDbLine UnHighlight...");
                }
                else if (entity.GetType() == typeof(Circle))
                {
                    ed.WriteMessage("\nAcDbCircle UnHighlight invalid...");
                    return; 
                }
            }
            base.Unhighlight(entity, subId, highlightAll);
        }

        public override bool IsApplicable(RXObject overruledSubject)
        {
            return overruledSubject.GetType() == typeof(Line) || overruledSubject.GetType() == typeof(Circle);
        }
    }

    class Commands
    {

        static MyHighlightOverrule g_highlightOverrule = null;

        [CommandMethod("HighlightOverruleOnOff")]
        static public void HighlightOverruleTest()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            if (g_highlightOverrule == null)
            {
                g_highlightOverrule = new MyHighlightOverrule();

                Overrule.AddOverrule(RXObject.GetClass(typeof(Line)), g_highlightOverrule, false);
                Overrule.AddOverrule(RXObject.GetClass(typeof(Circle)), g_highlightOverrule, false);
                Overrule.Overruling = true;

                ed.WriteMessage("\nHighlightOverrule is ON...");
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Line)), g_highlightOverrule);
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Circle)), g_highlightOverrule);
                Overrule.Overruling = false;
                g_highlightOverrule = null;

                ed.WriteMessage("\nHighlightOverrule is OFF...");
            }
        }
    }
}
