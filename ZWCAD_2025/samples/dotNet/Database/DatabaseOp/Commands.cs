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

[assembly: CommandClass(typeof(DatabaseOp.Commands))]

namespace DatabaseOp
{
    class Commands
    {
        [CommandMethod("CreateDwgTest")]
        static public void CreateDwgTest()
        {
            Document CurDoc = Application.DocumentManager.MdiActiveDocument;
            Editor curEd = CurDoc.Editor;

            Database db = new Database(/*true, false*/);
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = trans.GetObject(db.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord blockTableRecord = trans.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;

                Circle circle = new Circle(new Point3d(0, 0, 0), Vector3d.ZAxis, 500.0);
                blockTableRecord.AppendEntity(circle);

                trans.AddNewlyCreatedDBObject(circle, true);
                trans.Commit();
            }

            string dwgPath = System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\testDrawing2.dwg";
            try
            {
                db.SaveAs(dwgPath, DwgVersion.Current);
            }
            catch (System.Exception e)
            {
                curEd.WriteMessage("\nFailed to save! Exception: {0}", e.Message);
                return;
            }
            curEd.WriteMessage("\nSave successfully!");
        }

        [CommandMethod("ReadDwgFileTest")]
        static public void ReadDwgFileTest()
        {
            Document CurDoc = Application.DocumentManager.MdiActiveDocument;
            Editor curEd = CurDoc.Editor;

            Database db = new Database(false, true);
            string dwgPath = System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\testDrawing2.dwg";
            db.ReadDwgFile(dwgPath, FileOpenMode.OpenForReadAndAllShare, false, "");

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = trans.GetObject(db.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord blockTableRecord = trans.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForRead) as BlockTableRecord;

                Entity entity;
                foreach (ObjectId id in blockTableRecord)
                {
                    entity = trans.GetObject(id, OpenMode.ForRead) as Entity;
                    curEd.WriteMessage("\nClass name: {0}", entity.GetType());
                }
                trans.Commit();
            }
        }

        [CommandMethod("OpenDwgFileTest", CommandFlags.Session)]
        static public void OpenDwgFileTest()
        {
            string dwgPath = System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\testDrawing2.dwg";
            DocumentCollection docMgr = Application.DocumentManager;
            //Create a new document 
            //Document doc = docMgr.Add(dwgPath);
            Document doc = docMgr.Open(dwgPath, false);
            docMgr.MdiActiveDocument = doc;
        }
    }
}
