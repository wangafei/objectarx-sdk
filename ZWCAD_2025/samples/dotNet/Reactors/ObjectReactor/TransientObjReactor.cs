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

namespace ObjectReactor
{
    class TransientObjReactor
    {
        private DBObjectCollection m_DBObjectCollection;

        public TransientObjReactor()
        {
            m_DBObjectCollection = new DBObjectCollection();
        }

        public void AddDBObj(DBObject dBObject)
        {
            if (!m_DBObjectCollection.Contains(dBObject))
            {
                m_DBObjectCollection.Add(dBObject);
                DO(dBObject);
            }
            else
            {
                writeCalBakMsg("\nThe entity has registered an object reactor.");
            }
        }
        public void DelDBObj(DBObject dBObject)
        {
            if (m_DBObjectCollection.Contains(dBObject))
            {
                UNDOREAC(dBObject);
                m_DBObjectCollection.Remove(dBObject);
            }
            else
            {
                writeCalBakMsg("\nThis entity has no object reactor.");
            }
        }

        public void DO(DBObject dBObject)
        {
            try
            {
                dBObject.Cancelled += new EventHandler(callback_Cancelled);
                dBObject.Copied += new ObjectEventHandler(callback_Copied);
                dBObject.Erased += new ObjectErasedEventHandler(callback_Erased);
                dBObject.Goodbye += new EventHandler(callback_Goodbye);
                dBObject.Modified += new EventHandler(callback_Modified);
                dBObject.ModifiedXData += new EventHandler(callback_ModifiedXData);
                dBObject.ModifyUndone += new EventHandler(callback_ModifyUndone);
                dBObject.ObjectClosed += new ObjectClosedEventHandler(callback_ObjectClosed);
                dBObject.OpenedForModify += new EventHandler(callback_OpenedForModify);
                dBObject.Reappended += new EventHandler(callback_Reappended);
                dBObject.SubObjectModified += new ObjectEventHandler(callback_SubObjectModified);
                dBObject.Unappended += new EventHandler(callback_Unappended);
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.ToString(), "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void UNDOREAC(DBObject dBObject)
        {
            try
            {
                dBObject.Cancelled -= new EventHandler(callback_Cancelled);
                dBObject.Copied -= new ObjectEventHandler(callback_Copied);
                dBObject.Erased -= new ObjectErasedEventHandler(callback_Erased);
                dBObject.Goodbye -= new EventHandler(callback_Goodbye);
                dBObject.Modified -= new EventHandler(callback_Modified);
                dBObject.ModifiedXData -= new EventHandler(callback_ModifiedXData);
                dBObject.ModifyUndone -= new EventHandler(callback_ModifyUndone);
                dBObject.ObjectClosed -= new ObjectClosedEventHandler(callback_ObjectClosed);
                dBObject.OpenedForModify -= new EventHandler(callback_OpenedForModify);
                dBObject.Reappended -= new EventHandler(callback_Reappended);
                dBObject.SubObjectModified -= new ObjectEventHandler(callback_SubObjectModified);
                dBObject.Unappended -= new EventHandler(callback_Unappended);
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
        private void callback_Cancelled(object sender, EventArgs args)
        {
            writeCalBakMsg("\nCancelled");
        }
        private void callback_Copied(object sender, ObjectEventArgs args)
        {
            writeCalBakMsg("\nCopied");
        }
        private void callback_Erased(object sender, ObjectErasedEventArgs args)
        {
            writeCalBakMsg("\nErased");
        }
        private void callback_Goodbye(object sender, EventArgs args)
        {
            writeCalBakMsg("\nGoodbye");
        }
        private void callback_Modified(object sender, EventArgs args)
        {
            writeCalBakMsg("\nModified");
        }
        private void callback_ModifiedXData(object sender, EventArgs args)
        {
            writeCalBakMsg("\nModifiedXData");
        }
        private void callback_ModifyUndone(object sender, EventArgs args)
        {
            writeCalBakMsg("\nModifyUndone");
        }
        private void callback_ObjectClosed(object sender, ObjectClosedEventArgs args)
        {
            writeCalBakMsg("\nObjectClosed");
        }
        private void callback_OpenedForModify(object sender, EventArgs args)
        {
            writeCalBakMsg("\nOpenedForModify");
        }
        private void callback_Reappended(object sender, EventArgs args)
        {
            writeCalBakMsg("\nReappended");
        }
        private void callback_SubObjectModified(object sender, ObjectEventArgs args)
        {
            writeCalBakMsg("\nSubObjectModified");
        }
        private void callback_Unappended(object sender, EventArgs args)
        {
            writeCalBakMsg("\nUnappended");
        }
    }
}
