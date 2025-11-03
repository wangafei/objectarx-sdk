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

[assembly: CommandClass(typeof(DrawLine.Commands))]

namespace DrawLine
{
    class Commands
    {
        // Create a line
        [CommandMethod("DrawLine", CommandFlags.Modal)]
        static public void DrawLine()
        {
            Document objDoc = Application.DocumentManager.MdiActiveDocument;
            Database objDB = objDoc.Database;
            DocumentLock zcLock = objDoc.LockDocument();
            Transaction trans = objDoc.TransactionManager.StartTransaction();
            BlockTable zcBLT = (BlockTable)trans.GetObject(objDB.BlockTableId, OpenMode.ForRead);
            BlockTableRecord zcBLTR = (BlockTableRecord)trans.GetObject(zcBLT[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
            using (trans)
            {
                Point3d ptStart = new Point3d(0, 0, 0);
                Point3d ptEnd = new Point3d(100, 100, 0);
                Line objLine = new Line();
                objLine.StartPoint = ptStart;
                objLine.EndPoint = ptEnd;
                zcBLTR.AppendEntity(objLine);
                trans.AddNewlyCreatedDBObject(objLine, true);
                trans.Commit();
            }
            zcLock.Dispose();
        }

        // Modify by iterating lines in the database
        [CommandMethod("ModLine", CommandFlags.Modal)]
        static public void ModLine()
        {
            Document objDoc = Application.DocumentManager.MdiActiveDocument;
            Database objDB = objDoc.Database;
            DocumentLock zcLock = objDoc.LockDocument();
            using (Transaction trans = objDoc.TransactionManager.StartTransaction())
            {
                BlockTable zcBLT = (BlockTable)trans.GetObject(objDB.BlockTableId, OpenMode.ForRead);
                BlockTableRecord zcBlkTblRec = (BlockTableRecord)trans.GetObject(zcBLT[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;
                foreach (ObjectId entOid in zcBlkTblRec)
                {
                    Entity ent = trans.GetObject(entOid, OpenMode.ForWrite) as Entity;
                    if (ent != null && ent.GetType() == typeof(Line))
                    {
                        Line line = ent as Line;
                        Point3d startPoint = new Point3d(0, 100, 0);
                        Point3d endPoint = new Point3d(100, 0, 0);
                        line.StartPoint = startPoint;
                        line.EndPoint = endPoint;
                    }
                }
                trans.Commit();
            }
            zcLock.Dispose();
        }

        // Delete by interactively selecting a line
        [CommandMethod("EraseLine", CommandFlags.Modal)]
        static public void EraseLine()
        {
            Document objDoc = Application.DocumentManager.MdiActiveDocument;
            PromptEntityResult result = objDoc.Editor.GetEntity("\nSelect a line");
            if (result.Status != PromptStatus.OK)
                return;

            DocumentLock zcLock = objDoc.LockDocument();
            Transaction trans = objDoc.TransactionManager.StartTransaction();
            using (trans)
            {
                Entity entity = (Entity)trans.GetObject(result.ObjectId, OpenMode.ForWrite);
                if (entity != null && entity.GetType() == typeof(Line))
                {
                    Line line = entity as Line;
                    line.Erase();
                }
                trans.Commit();
            }
            zcLock.Dispose();
        }
    }
}
