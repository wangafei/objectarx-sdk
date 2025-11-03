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

[assembly: CommandClass(typeof(XData.Commands))]

namespace XData
{
    class Commands
    {
        [CommandMethod("AddXData")]
        static public void AddXData()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptEntityResult result = doc.Editor.GetEntity("\nSelect the entity");
            if (result.Status != PromptStatus.OK)
            {
                return;
            }
            Transaction trans = doc.TransactionManager.StartTransaction();
            using (trans)
            {
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                RegAppTable regTable = (RegAppTable)trans.GetObject(db.RegAppTableId, OpenMode.ForWrite);
                String strAppName = "XData";
                if (!regTable.Has(strAppName))
                {
                    RegAppTableRecord regAppTableRecord = new RegAppTableRecord();
                    regAppTableRecord.Name = strAppName;
                    regTable.Add(regAppTableRecord);
                    trans.AddNewlyCreatedDBObject(regAppTableRecord, true);
                    if (entity != null)
                    {
                        entity.XData = new ResultBuffer(new TypedValue((int)DxfCode.ExtendedDataRegAppName, strAppName),
                            new TypedValue((int)DxfCode.ExtendedDataAsciiString, "hello"),
                            new TypedValue((int)DxfCode.ExtendedDataInteger32, 2),
                            new TypedValue((int)DxfCode.ExtendedDataReal, 3.14));
                    }
                }
                else
                {
                    ed.WriteMessage("\nExtended data with the same name already exists.");
                }
                trans.Commit();
            }
        }

        [CommandMethod("ModXData")]
        static public void ModXData()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptEntityResult result = doc.Editor.GetEntity("\nSelect the entity");
            if (result.Status != PromptStatus.OK)
            {
                return;
            }
            Transaction trans = doc.TransactionManager.StartTransaction();
            using (trans)
            {
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                RegAppTable regTable = (RegAppTable)trans.GetObject(db.RegAppTableId, OpenMode.ForWrite);
                String strAppName = "XData";
                if (regTable.Has(strAppName))
                {
                    if (entity != null)
                    {
                        if (entity.XData != null)
                        {
                            entity.XData = new ResultBuffer(new TypedValue((int)DxfCode.ExtendedDataRegAppName, strAppName),
                                new TypedValue((int)DxfCode.ExtendedDataAsciiString, "Mod"),
                                new TypedValue((int)DxfCode.ExtendedDataInteger32, 1),
                                new TypedValue((int)DxfCode.ExtendedDataReal, 6.28));
                        }
                        else
                        {
                            ed.WriteMessage("\nThe entity has no extended data.");
                        }

                    }
                }
                else
                {
                    ed.WriteMessage("\nThe extended data with this name does not exist.");
                }
                trans.Commit();
            }
        }

        [CommandMethod("DelXData")]
        static public void DelXData()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptEntityResult result = doc.Editor.GetEntity("\nSelect the entity");
            if (result.Status != PromptStatus.OK)
            {
                return;
            }
            Transaction trans = doc.TransactionManager.StartTransaction();
            using (trans)
            {
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                RegAppTable regTable = (RegAppTable)trans.GetObject(db.RegAppTableId, OpenMode.ForWrite);
                String strAppName = "XData";
                if (regTable.Has(strAppName))
                {
                    if (entity != null && entity.XData != null)
                    {
                        entity.XData = new ResultBuffer(new TypedValue((int)DxfCode.ExtendedDataRegAppName, "XData"));
                    }
                    else
                    {
                        ed.WriteMessage("\nThe entity has no extended data.");
                    }
                }
                else
                {
                    ed.WriteMessage("\nThe extended data with this name does not exist.");
                }
                trans.Commit();
            }
        }
    }
}
