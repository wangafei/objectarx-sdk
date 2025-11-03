using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;
using Application = ZwSoft.ZwCAD.ApplicationServices.Application;

namespace DataBaseReactor
{
    class DBReactor
    {
        private Database m_db;
        public DBReactor()
        {
            m_db = HostApplicationServices.WorkingDatabase;
            DO();
        }

        public void DO()
        {
            try
            {
                m_db.ObjectAppended += new ObjectEventHandler(callback_ObjectAppended);
                m_db.ObjectErased += new ObjectErasedEventHandler(callback_ObjectErased);
                m_db.ObjectModified += new ObjectEventHandler(callback_ObjectModified);
                m_db.ObjectOpenedForModify += new ObjectEventHandler(callback_ObjectOpenedForModify);
                m_db.ObjectReappended += new ObjectEventHandler(callback_ObjectReappended);
                m_db.ObjectUnappended += new ObjectEventHandler(callback_ObjectUnappended);
                m_db.SystemVariableChanged += new ZwSoft.ZwCAD.DatabaseServices.SystemVariableChangedEventHandler(callback_SystemVariableChanged);
                m_db.SystemVariableWillChange += new ZwSoft.ZwCAD.DatabaseServices.SystemVariableChangingEventHandler(callback_SystemVariableWillChange);
                m_db.ProxyResurrectionCompleted += new ProxyResurrectionCompletedEventHandler(callback_ProxyResurrectionCompleted);
                //TODO     more events
            }
            catch(System.Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            
        }

        public void UNDO()
        {
            try
            {
                m_db.ObjectAppended -= new ObjectEventHandler(callback_ObjectAppended);
                m_db.ObjectErased -= new ObjectErasedEventHandler(callback_ObjectErased);
                m_db.ObjectModified -= new ObjectEventHandler(callback_ObjectModified);
                m_db.ObjectOpenedForModify -= new ObjectEventHandler(callback_ObjectOpenedForModify);
                m_db.ObjectReappended -= new ObjectEventHandler(callback_ObjectReappended);
                m_db.ObjectUnappended -= new ObjectEventHandler(callback_ObjectUnappended);
                m_db.SystemVariableChanged -= new ZwSoft.ZwCAD.DatabaseServices.SystemVariableChangedEventHandler(callback_SystemVariableChanged);
                m_db.SystemVariableWillChange -= new ZwSoft.ZwCAD.DatabaseServices.SystemVariableChangingEventHandler(callback_SystemVariableWillChange);
                m_db.ProxyResurrectionCompleted -= new ProxyResurrectionCompletedEventHandler(callback_ProxyResurrectionCompleted);
                //TODO     more events
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void writeCalBakMsg(string str)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;
            ed.WriteMessage(str);
        }

        private void callback_ObjectAppended(object sender, ObjectEventArgs e)
        {
            writeCalBakMsg("\nObjectAppended");
        }

        private void callback_ObjectErased(object sender, ObjectErasedEventArgs e)
        {
            writeCalBakMsg("\nObjectErased");
        }

        private void callback_ObjectModified(object sender, ObjectEventArgs e)
        {
            writeCalBakMsg("\nObjectModified");
        }

        private void callback_ObjectOpenedForModify(object sender, ObjectEventArgs e)
        {
            writeCalBakMsg("\nObjectOpenedForModify");
        }

        private void callback_ObjectReappended(object sender, ObjectEventArgs e)
        {
            writeCalBakMsg("\nObjectReappended");
        }

        private void callback_ObjectUnappended(object sender, ObjectEventArgs e)
        {
            writeCalBakMsg("\nObjectUnappended");
        }

        private void callback_SystemVariableChanged(object sender, ZwSoft.ZwCAD.DatabaseServices.SystemVariableChangedEventArgs e)
        {
            writeCalBakMsg("\nSystemVariableChanged");
        }
        private void callback_SystemVariableWillChange(object sender, ZwSoft.ZwCAD.DatabaseServices.SystemVariableChangingEventArgs e)
        {
            writeCalBakMsg("\nSystemVariableWillChange");
        }

        private void callback_ProxyResurrectionCompleted(object sender, ProxyResurrectionCompletedEventArgs e)
        {
            writeCalBakMsg("\nProxyResurrectionCompleted");
        }
    }
}
