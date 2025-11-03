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

[assembly: CommandClass(typeof(EditorReactor.Commands))]

namespace EditorReactor
{
    class Commands
    {
        private Editor _editor = Application.DocumentManager.MdiActiveDocument.Editor;

        [CommandMethod("EditorReactorOnOff")]
        public void EditorReactorOnOff()
        {
            if (CEditorReactor.IsAdded)
            {
                CEditorReactor.TheNetEditorReactor.RemoveEventHandler();
            }
            else
            {
                CEditorReactor.TheNetEditorReactor.AddEventHandler();
            }
            CEditorReactor.IsAdded = !CEditorReactor.IsAdded;
            _editor.WriteMessage("\nEditorReactor is {0}...", CEditorReactor.IsAdded ? "on" : "off");
        }
    }
}
