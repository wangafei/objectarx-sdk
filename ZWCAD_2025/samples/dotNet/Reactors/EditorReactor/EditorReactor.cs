using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;
using ZwSoft.ZwCAD.Runtime;
using Application = ZwSoft.ZwCAD.ApplicationServices.Application;

namespace EditorReactor
{
    class CEditorReactor
    {
        static public CEditorReactor TheNetEditorReactor { get; } = new CEditorReactor();
        static public bool IsAdded { get; set; } = false;

        private Document _document = Application.DocumentManager.MdiActiveDocument;
        private Editor _editor = Application.DocumentManager.MdiActiveDocument.Editor;

        public CEditorReactor() { }

        public void AddEventHandler()
        {
            try
            {
                _document.CommandWillStart += new CommandEventHandler(callback_CommandWillStart);
                _document.CommandEnded += new CommandEventHandler(callback_CommandEnded);
                _document.CommandCancelled += new CommandEventHandler(callback_CommandCancelled);
                _document.BeginDwgOpen += new DrawingOpenEventHandler(callback_BeginDwgOpen);
                _document.EndDwgOpen += new DrawingOpenEventHandler(callback_EndDwgOpen);
                _document.ViewChanged += new EventHandler(callback_ViewChanged);
                _document.LispWillStart += new LispWillStartEventHandler(callback_LispWillStart);
                _document.LispEnded += new EventHandler(callback_LispEnded);
                //TODO: More events.
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        public void RemoveEventHandler()
        {
            try
            {
                _document.CommandWillStart -= new CommandEventHandler(callback_CommandWillStart);
                _document.CommandEnded -= new CommandEventHandler(callback_CommandEnded);
                _document.CommandCancelled -= new CommandEventHandler(callback_CommandCancelled);
                _document.BeginDwgOpen -= new DrawingOpenEventHandler(callback_BeginDwgOpen);
                _document.EndDwgOpen -= new DrawingOpenEventHandler(callback_EndDwgOpen);
                _document.ViewChanged -= new EventHandler(callback_ViewChanged);
                _document.LispWillStart -= new LispWillStartEventHandler(callback_LispWillStart);
                _document.LispEnded -= new EventHandler(callback_LispEnded);
                //TODO: More events.
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void callback_CommandWillStart(object sender, CommandEventArgs e)
        {
            _editor.WriteMessage("\ncallback_CommandWillStart: {0}", e.GlobalCommandName);
        }

        private void callback_CommandEnded(object sender, CommandEventArgs e)
        {
            _editor.WriteMessage("\ncallback_CommandEnded: {0}", e.GlobalCommandName);
        }

        private void callback_CommandCancelled(object sender, CommandEventArgs e)
        {
            _editor.WriteMessage("\ncallback_CommandCancelled: {0}", e.GlobalCommandName);
        }

        private void callback_BeginDwgOpen(object sender, DrawingOpenEventArgs e)
        {
            _editor.WriteMessage("\ncallback_BeginDwgOpen: {0}", e.FileName);
        }

        private void callback_EndDwgOpen(object sender, DrawingOpenEventArgs e)
        {
            _editor.WriteMessage("\ncallback_EndDwgOpen: {0}", e.FileName);
        }

        private void callback_ViewChanged(object sender, EventArgs e)
        {
            _editor.WriteMessage("\ncallback_ViewChanged");
        }

        private void callback_LispWillStart(object sender, LispWillStartEventArgs e)
        {
            _editor.WriteMessage("\ncallback_LispWillStart: {0}", e.FirstLine);
        }

        private void callback_LispEnded(object sender, EventArgs e)
        {
            _editor.WriteMessage("\ncallback_LispEnded");
        }
    }
}
