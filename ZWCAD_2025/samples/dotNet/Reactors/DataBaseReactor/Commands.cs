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

[assembly: CommandClass(typeof(DataBaseReactor.Commands))]

namespace DataBaseReactor
{
    class Commands
    {
        public static DBReactor m_DBReactor;

        [CommandMethod("AddReactor")]
        static public void AddReactor()
        {
            if (m_DBReactor == null)
            {
                m_DBReactor = new DBReactor();
            }
            else
            {
                m_DBReactor.DO();
            }
        }

        [CommandMethod("RemoveReactor")]
        static public void RemoveReactor()
        {
            if (m_DBReactor != null)
            {
                m_DBReactor.UNDO();
            }
        }
    }
}
