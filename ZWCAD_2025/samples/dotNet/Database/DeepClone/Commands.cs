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
using ZwSoft.ZwCAD.Windows;

[assembly: CommandClass(typeof(DeepClone.Commands))]

namespace DeepClone
{
    class Commands
    {
        static public void getMsEnts(Database db, ObjectIdCollection objectIdCollection)
        {
            ZwSoft.ZwCAD.DatabaseServices.TransactionManager tm = db.TransactionManager;
            using (Transaction myT = tm.StartTransaction())
            {
                BlockTable bt = (BlockTable)tm.GetObject(db.BlockTableId, OpenMode.ForRead, false);
                BlockTableRecord btr = (BlockTableRecord)tm.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead, false);
                foreach (ObjectId id in btr)
                {
                    if (id != null)
                        objectIdCollection.Add(id);
                }
                myT.Commit();
            }
        }

        [CommandMethod("DeepCloneDiffOwnerObjects")]
        static public void DeepCloneDiffOwnerObjects()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptSelectionOptions selOptsMS = new PromptSelectionOptions();
            selOptsMS.MessageForAdding = "Select entities to clone(clone to the model space)";
            PromptSelectionResult selResMS = ed.GetSelection(selOptsMS);
            if (selResMS.Status != PromptStatus.OK)
                return;
            SelectionSet sSetMS = selResMS.Value;
            ObjectId[] objIdsMS = sSetMS.GetObjectIds();

            PromptSelectionOptions selOptsPS = new PromptSelectionOptions();
            selOptsPS.MessageForAdding = "Select entities to clone(clone to the paper space)";
            PromptSelectionResult selResPS = ed.GetSelection(selOptsPS);
            if (selResPS.Status != PromptStatus.OK)
                return;
            SelectionSet sSetPS = selResPS.Value;
            ObjectId[] objIdsPS = sSetPS.GetObjectIds();

            ObjectId ownerId = ObjectId.Null;
            ObjectIdCollection objectIdCollectionMS = new ObjectIdCollection();
            using (Transaction zcTrans = doc.TransactionManager.StartTransaction())
            {
                for (int i = 0; i < objIdsMS.Length; i++)
                {
                    DBObject obj = zcTrans.GetObject(objIdsMS[i], OpenMode.ForRead);
                    if (obj.OwnerId == ownerId)
                    {
                        objectIdCollectionMS.Add(objIdsMS[i]);
                    }
                    else if (i == 0)
                    {
                        ownerId = obj.OwnerId;
                        objectIdCollectionMS.Add(objIdsMS[i]);
                    }
                }
                zcTrans.Commit();
            }

            ownerId = ObjectId.Null;
            ObjectIdCollection objectIdCollectionPS = new ObjectIdCollection();
            using (Transaction zcTrans = doc.TransactionManager.StartTransaction())
            {
                for (int i = 0; i < objIdsPS.Length; i++)
                {
                    DBObject obj = zcTrans.GetObject(objIdsPS[i], OpenMode.ForRead);
                    if (obj.OwnerId == ownerId)
                    {
                        objectIdCollectionPS.Add(objIdsPS[i]);
                    }
                    else if (i == 0)
                    {
                        ownerId = obj.OwnerId;
                        objectIdCollectionPS.Add(objIdsPS[i]);
                    }
                }
                zcTrans.Commit();
            }

            ObjectId modelspaceId = SymbolUtilityServices.GetBlockModelSpaceId(db);
            ObjectId paperspaceId = SymbolUtilityServices.GetBlockPaperSpaceId(db);
            IdMapping idMapping = new IdMapping();
            db.DeepCloneObjects(objectIdCollectionMS, modelspaceId, idMapping, false);
            db.DeepCloneObjects(objectIdCollectionPS, paperspaceId, idMapping, false);
        }

        [CommandMethod("WblockSample")]
        static public void WblockSample()
        {
            ObjectIdCollection objectIdCollection = new ObjectIdCollection();
            String str = null;

            OpenFileDialog openFile = new OpenFileDialog("Choose the dwg file", null, "dwg", null, 0);
            System.Windows.Forms.DialogResult dlr = openFile.ShowDialog();
            if (System.Windows.Forms.DialogResult.OK == dlr)
            {
                str = openFile.Filename;
            }
            else
            {
                return;
            }

            Database db = new Database(false, true);
            db.ReadDwgFile(str, FileOpenMode.OpenForReadAndAllShare, false, null);

            getMsEnts(db, objectIdCollection);

            Database destDb = db.Wblock(objectIdCollection, Point3d.Origin);
            String strPath = System.IO.Path.GetDirectoryName(str) + "\\" +
              System.IO.Path.GetFileNameWithoutExtension(str) + "_WblockTest.dwg";
            destDb.SaveAs(strPath, DwgVersion.Current);
        }

        [CommandMethod("WblockCloneObjectsSample")]
        static public void WblockCloneObjectsSample()
        {
            Database zwDb = HostApplicationServices.WorkingDatabase;
            Document zwDoc = Application.DocumentManager.GetDocument(zwDb);
            ObjectIdCollection objectIdCollection = new ObjectIdCollection();
            String str = null;

            OpenFileDialog openFile = new OpenFileDialog("Choose the dwg file", null, "dwg", null, 0);
            System.Windows.Forms.DialogResult dlr = openFile.ShowDialog();
            if (System.Windows.Forms.DialogResult.OK == dlr)
            {
                str = openFile.Filename;
            }
            else
            {
                return;
            }

            try
            {
                Database db = new Database(false, true);
                db.ReadDwgFile(str, FileOpenMode.OpenForReadAndAllShare, false, null);

                getMsEnts(db, objectIdCollection);

                IdMapping idMap = new IdMapping();
                zwDb.WblockCloneObjects(objectIdCollection, zwDb.CurrentSpaceId, idMap, DuplicateRecordCloning.Replace, false);
            }
            catch (ZwSoft.ZwCAD.Runtime.Exception ex)
            {
                zwDoc.Editor.WriteMessage(ex.ToString());
            }
        }
    }
}
