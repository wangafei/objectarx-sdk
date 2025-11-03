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

[assembly: CommandClass(typeof(ObjectReactor.Commands))]

namespace ObjectReactor
{
    class Commands
    {
        public static TransientObjReactor m_transientObjReactor;

        [CommandMethod("AddObjReactor")]
        static public void AddObjReactor()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptEntityResult result = ed.GetEntity("\nSelect the entity");
            if (result.Status != PromptStatus.OK)
            {
                return;
            }
            Transaction trans = doc.TransactionManager.StartTransaction();
            using (trans)
            {
                DBObject entity = trans.GetObject(result.ObjectId, OpenMode.ForRead);
                if (m_transientObjReactor == null)
                {
                    m_transientObjReactor = new TransientObjReactor();
                    m_transientObjReactor.AddDBObj(entity);
                }
                else
                {
                    m_transientObjReactor.AddDBObj(entity);
                }
                trans.Commit();
            }

        }

        [CommandMethod("DelObjReactor")]
        static public void DelObjReactor()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptEntityResult result = ed.GetEntity("\nSelect the entity");
            if (result.Status != PromptStatus.OK)
            {
                return;
            }
            Transaction trans = doc.TransactionManager.StartTransaction();
            using (trans)
            {
                DBObject entity = trans.GetObject(result.ObjectId, OpenMode.ForRead);
                if (m_transientObjReactor != null)
                {
                    m_transientObjReactor.DelDBObj(entity);
                }
                trans.Commit();
            }
        }
    }
}
