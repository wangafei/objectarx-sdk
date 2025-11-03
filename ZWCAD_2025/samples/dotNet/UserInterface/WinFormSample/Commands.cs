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

[assembly: CommandClass(typeof(WinFormSample.Commands))]

namespace WinFormSample
{
    class Commands
    {
        [CommandMethod("WinFormSample")]
        static public void WinFormSample()
        {
            SampleDlg form = new SampleDlg();
            Application.ShowModelessDialog(form);
        }
    }
}
