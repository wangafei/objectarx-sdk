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

[assembly: CommandClass(typeof(PlotSample.Commands))]

namespace PlotSample
{
    class Commands
    {
        [CommandMethod("PlotNetSample")]
        static public void PlotNetSample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            SampleDlg form = new SampleDlg();
            Application.ShowModalDialog(form);
        }
    }
}
