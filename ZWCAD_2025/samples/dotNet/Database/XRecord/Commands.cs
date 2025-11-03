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

[assembly: CommandClass(typeof(XRecord.Commands))]

namespace XRecord
{
    class Commands
    {
        [CommandMethod("AddXRecord")]
        static public void AddXRecord()
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
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                if (entity.ExtensionDictionary == ObjectId.Null)
                {
                    entity.CreateExtensionDictionary();
                }
                ObjectId objId = entity.ExtensionDictionary;
                DBDictionary dict = (DBDictionary)trans.GetObject(objId, OpenMode.ForWrite);
                if (!dict.Contains("XRecord"))
                {
                    Xrecord xrecord = new Xrecord();
                    ResultBuffer rb = new ResultBuffer(new TypedValue((int)DxfCode.Text, "hello"),
                        new TypedValue((int)DxfCode.Int32, 2),
                        new TypedValue((int)DxfCode.Real, 3.14));
                    xrecord.Data = rb;
                    dict.SetAt("XRecord", xrecord);
                    trans.AddNewlyCreatedDBObject(xrecord, true);
                }
                else
                {
                    ed.WriteMessage("\nAn extension dictionary with the same name already exists for this entity.");
                }

                trans.Commit();
            }
        }

        [CommandMethod("ModXRecord")]
        static public void ModXRecord()
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
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                ObjectId objId = entity.ExtensionDictionary;
                if (objId != ObjectId.Null)
                {
                    DBDictionary dict = (DBDictionary)trans.GetObject(objId, OpenMode.ForWrite);
                    if (dict.Contains("XRecord"))
                    {
                        ObjectId XrecId = dict.GetAt("XRecord");
                        Xrecord xrecord = (Xrecord)trans.GetObject(XrecId, OpenMode.ForWrite);
                        if (xrecord == null)
                        {
                            return;
                        }
                        ResultBuffer rb = new ResultBuffer(new TypedValue((int)DxfCode.Text, "MOD"),
                            new TypedValue((int)DxfCode.Int32, 1),
                            new TypedValue((int)DxfCode.Real, 6.28));
                        xrecord.Data = rb;
                    }
                }
                else
                {
                    ed.WriteMessage("\nThe entity has no extension dictionary called \"XRecord\".");
                }
                trans.Commit();
            }
        }

        [CommandMethod("DelXRecord")]
        static public void DelXRecord()
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
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                ObjectId objId = entity.ExtensionDictionary;
                if (objId != ObjectId.Null)
                {
                    DBDictionary dict = (DBDictionary)trans.GetObject(objId, OpenMode.ForWrite);
                    if (dict.Contains("XRecord"))
                    {
                        dict.Remove("XRecord");
                    }
                    entity.ReleaseExtensionDictionary();
                }
                else
                {
                    ed.WriteMessage("\nThe entity has no extension dictionary.");
                }
                trans.Commit();
            }
        }
    }
}
