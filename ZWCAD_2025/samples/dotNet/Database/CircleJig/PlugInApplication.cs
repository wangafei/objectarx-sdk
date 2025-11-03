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

[assembly: ExtensionApplication(typeof(CircleJig.PlugInApplication))]

namespace CircleJig
{
    public class PlugInApplication : IExtensionApplication
    {
        public void Initialize()
        {
            // Add your initialize code here.
        }

        public void Terminate()
        {
            // Add your uninitialize code here.
        }
    }
}
