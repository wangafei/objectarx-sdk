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

[assembly: CommandClass(typeof(WPFSample.Commands))]

namespace WPFSample
{
    class Commands
    {
        [CommandMethod("HelloWPf")]
        static public void HelloWPf()
        {
            Window1 window1 = new Window1();
            window1.ShowDialog();
        }
    }
}
