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

[assembly: CommandClass(typeof(InsertBlock.Commands))]

namespace InsertBlock
{
    public class BlockReferenceParam
    {
        public string BlockName { get; set; }
        public Point3d Position { get; set; }
        public double Rotation { get; set; }
        public double Scale { get; set; }
    }

    class Commands
    {
        static public void InsertBlock(BlockReferenceParam blkRefParam)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);

                if (!blockTable.Has(blkRefParam.BlockName))
                {
                    ed.WriteMessage("\nThe Block doesn't exist!");
                    return;
                }
                else
                {
                    BlockTableRecord newBlkRec = (BlockTableRecord)trans.GetObject(blockTable[blkRefParam.BlockName], OpenMode.ForRead);

                    BlockTableRecord msBlkRec = (BlockTableRecord)trans.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
                    BlockReference blockRef = new BlockReference(newBlkRec.Origin, newBlkRec.ObjectId);
                    blockRef.SetDatabaseDefaults();
                    blockRef.Position = blkRefParam.Position;
                    blockRef.ScaleFactors = new Scale3d(blkRefParam.Scale);
                    blockRef.Rotation = blkRefParam.Rotation;

                    msBlkRec.AppendEntity(blockRef);
                    trans.AddNewlyCreatedDBObject(blockRef, true);

                    if (newBlkRec.HasAttributeDefinitions)
                    {
                        foreach (ObjectId objId in newBlkRec)
                        {
                            DBObject dbObj = trans.GetObject(objId, OpenMode.ForRead) as DBObject;

                            if (dbObj is AttributeDefinition)
                            {
                                AttributeDefinition attDef = dbObj as AttributeDefinition;

                                using (AttributeReference attRef = new AttributeReference())
                                {
                                    attRef.SetAttributeFromBlock(attDef, blockRef.BlockTransform);
                                    blockRef.AttributeCollection.AppendAttribute(attRef);
                                    trans.AddNewlyCreatedDBObject(attRef, true);
                                }
                            }
                        }
                    }
                }
                trans.Commit();
            }
        }

        [CommandMethod("CreateBlockTest1")]
        static public void CreateBlockTest1()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            DocumentLock docLock = doc.LockDocument();
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);

                BlockTableRecord newBlkRec = new BlockTableRecord();
                newBlkRec.Name = "MyBlock1";
                newBlkRec.Origin = new Point3d(1000, 1000, 0);

                if (blockTable.Has(newBlkRec.Name))
                {
                    ed.WriteMessage("\nThe block already exists!");
                    return;
                }
                blockTable.UpgradeOpen();
                ObjectId newBlkRecId = blockTable.Add(newBlkRec);
                trans.AddNewlyCreatedDBObject(newBlkRec, true);

                DBObjectCollection ents = new DBObjectCollection();
                Point3d ptCtr = new Point3d(1000, 1000, 0);
                Circle circle = new Circle(ptCtr, Vector3d.ZAxis, 200.0);
                ents.Add(circle);
                Point3d ptSt1 = new Point3d(1000, 750, 0);
                Point3d ptEd1 = new Point3d(1000, 1250, 0);
                Line line1 = new Line(ptSt1, ptEd1);
                ents.Add(line1);
                Point3d ptSt2 = new Point3d(750, 1000, 0);
                Point3d ptEd2 = new Point3d(1250, 1000, 0);
                Line line2 = new Line(ptSt2, ptEd2);
                ents.Add(line2);

                foreach (Entity ent in ents)
                {
                    newBlkRec.AppendEntity(ent);
                    trans.AddNewlyCreatedDBObject(ent, true);
                }

                BlockTableRecord msBlkRec = (BlockTableRecord)trans.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForWrite);
                BlockReference blockRef = new BlockReference(ptCtr, newBlkRecId);
                msBlkRec.AppendEntity(blockRef);
                trans.AddNewlyCreatedDBObject(blockRef, true);

                trans.Commit();
            }
            docLock.Dispose();
        }

        [CommandMethod("CreateBlockTest2")]
        static public void CreateBlockTest2()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.MessageForAdding = "Select some entities:";
            PromptSelectionResult selRes = ed.GetSelection(selOpts);
            if (selRes.Status != PromptStatus.OK)
            {
                ed.WriteMessage("\nNo entity selected!");
                return;
            }
            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            BlockReferenceParam blkRefParam = new BlockReferenceParam();
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);

                BlockTableRecord newBlkRec = new BlockTableRecord();
                newBlkRec.Name = "MyBlock2";
                newBlkRec.Origin = new Point3d(1000, 1000, 0);

                if (blockTable.Has(newBlkRec.Name))
                {
                    ed.WriteMessage("\nThe block already exists!");
                    return;
                }
                blockTable.UpgradeOpen();
                ObjectId newBlkRecId = blockTable.Add(newBlkRec);
                trans.AddNewlyCreatedDBObject(newBlkRec, true);

                Extents3d extAll = new Extents3d();
                foreach (ObjectId objId in objIds)
                {
                    Entity subEnt = (Entity)objId.GetObject(OpenMode.ForWrite);
                    Extents3d extCur = subEnt.GeometricExtents;
                    extAll.AddExtents(extCur);

                    Entity ent = (Entity)subEnt.Clone();
                    subEnt.Erase();
                    newBlkRec.AppendEntity(ent);
                    trans.AddNewlyCreatedDBObject(ent, true);
                }

                Point3d ptMin = extAll.MinPoint;
                Point3d ptMax = extAll.MaxPoint;
                Point3d ptCtr = new Point3d(ptMin.X / 2 + ptMax.X / 2, ptMin.Y / 2 + ptMax.Y / 2, ptMin.Z / 2 + ptMax.Z / 2);
                newBlkRec.Origin = ptMin;

                AttributeDefinition attDef = new AttributeDefinition();
                attDef.Position = ptCtr;
                attDef.Verifiable = true;
                attDef.Tag = "AttTag";
                attDef.TextString = "AAAAA";
                attDef.ColorIndex = 1;
                attDef.Height = ptMin.DistanceTo(ptMax) / 10;

                newBlkRec.AppendEntity(attDef);
                trans.AddNewlyCreatedDBObject(attDef, true);

                blkRefParam.BlockName = newBlkRec.Name;
                blkRefParam.Position = newBlkRec.Origin;
                blkRefParam.Rotation = 0.0;
                blkRefParam.Scale = 1.0;

                trans.Commit();
            }

            InsertBlock(blkRefParam);
        }

        [CommandMethod("InsertBlockTest")]
        static public void InsertBlockTest()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            BlockReferenceParam blkRefParam = new BlockReferenceParam();
            blkRefParam.BlockName = null;
            blkRefParam.Position = new Point3d(0, 0, 0);
            blkRefParam.Rotation = 0.0;
            blkRefParam.Scale = 1.0;

            PromptStringOptions strOpts = new PromptStringOptions("Enter block name");
            strOpts.AllowSpaces = false;
            PromptResult strRes = ed.GetString(strOpts);
            if (strRes.Status == PromptStatus.OK)
                blkRefParam.BlockName = strRes.StringResult;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blockTable = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);

                if (!blockTable.Has(blkRefParam.BlockName))
                {
                    ed.WriteMessage("\nThe Block doesn't exist!");
                    return;
                }
            }

            PromptPointOptions ptOpts = new PromptPointOptions("Pick insert position");
            ptOpts.AllowNone = false;
            PromptPointResult ptRes = ed.GetPoint(ptOpts);
            if (ptRes.Status == PromptStatus.OK)
                blkRefParam.Position = ptRes.Value;

            PromptDoubleOptions dblOptsRt = new PromptDoubleOptions("Enter the Rotation");
            dblOptsRt.AllowNone = false;
            PromptDoubleResult dblResRt = ed.GetDouble(dblOptsRt);
            if (dblResRt.Status == PromptStatus.OK)
                blkRefParam.Rotation = dblResRt.Value;

            PromptDoubleOptions dblOptsScale = new PromptDoubleOptions("Enter the ScaleFactor");
            dblOptsScale.AllowNone = false;
            PromptDoubleResult dblResScale = ed.GetDouble(dblOptsScale);
            if (dblResScale.Status == PromptStatus.OK)
                blkRefParam.Scale = dblResScale.Value;

            InsertBlock(blkRefParam);
        }
    }
}
