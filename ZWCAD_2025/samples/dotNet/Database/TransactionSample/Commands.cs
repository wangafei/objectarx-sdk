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

[assembly: CommandClass(typeof(TransactionSample.Commands))]

namespace TransactionSample
{
    class Commands
    {
        [CommandMethod("NestedTransaction")]
        static public void NestedTransaction()
        {
            Document zcDoc = Application.DocumentManager.MdiActiveDocument;
            Database zcCurDb = zcDoc.Database;

            ZwSoft.ZwCAD.DatabaseServices.TransactionManager zcTransMgr;
            zcTransMgr = zcCurDb.TransactionManager;
            // Add entities into the database through transaction
            using (Transaction zcTrans = zcTransMgr.StartTransaction())
            {
                BlockTable zcBlkTbl = zcTrans.GetObject(zcCurDb.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord zcBlkTblRec = zcTrans.GetObject(zcBlkTbl[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;

                Line line = new Line(new Point3d(0, 0, 0), new Point3d(100, 100, 0));
                line.SetDatabaseDefaults();
                zcBlkTblRec.AppendEntity(line);
                zcTrans.AddNewlyCreatedDBObject(line, true);
                zcTrans.Commit();
            }

            // Modify the data of existing entities and rollback operations through nested transaction
            using (Transaction zcTrans1 = zcTransMgr.StartTransaction())
            {
                BlockTable zcBlkTbl = zcTrans1.GetObject(zcCurDb.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord zcBlkTblRec = zcTrans1.GetObject(zcBlkTbl[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;
                foreach (ObjectId entOid in zcBlkTblRec)
                {
                    Entity ent = zcTrans1.GetObject(entOid, OpenMode.ForWrite) as Entity;
                    if (ent != null && ent.GetType() == typeof(Line))
                    {
                        Line line = ent as Line;
                        line.ColorIndex = 1;
                    }
                }

                using (Transaction zcTrans2 = zcTransMgr.StartTransaction())
                {
                    Line zcLine = new Line(new Point3d(0, 100, 0), new Point3d(100, 0, 0));
                    zcLine.SetDatabaseDefaults();
                    zcLine.ColorIndex = 3;

                    zcBlkTblRec.AppendEntity(zcLine);
                    zcTrans2.AddNewlyCreatedDBObject(zcLine, true);

                    zcTrans2.Abort();
                }
                zcTrans1.Commit();
            }
        }
    }
}
