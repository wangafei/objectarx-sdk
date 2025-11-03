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

[assembly: CommandClass(typeof(MakeText.Commands))]

namespace MakeText
{
    class Commands
    {
        [CommandMethod("TextSample")]
        static public void TextSample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);

            // Add entities into the database through the transaction.
            using (Transaction zcTrans = db.TransactionManager.StartTransaction())
            {
                TextStyleTable zcTxtStyTbl = zcTrans.GetObject(db.TextStyleTableId, OpenMode.ForWrite) as TextStyleTable;
                string styleName = "Standard";
                ObjectId objId = new ObjectId();
                if (zcTxtStyTbl.Has(styleName))
                {
                    foreach (ObjectId id in zcTxtStyTbl)
                    {
                        TextStyleTableRecord strrec = (TextStyleTableRecord)zcTrans.GetObject(id, OpenMode.ForRead);
                        if (strrec.Name == "Standard")
                        {
                            objId = id;
                            break;
                        }
                    }
                }
                else
                {
                    return;
                }

                BlockTable zcBlkTbl = zcTrans.GetObject(db.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord zcBlkTblRec = zcTrans.GetObject(zcBlkTbl[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;

                DBText txt = new DBText();
                txt.Position = Point3d.Origin;
                txt.Height = 50;
                txt.Rotation = 0;
                txt.TextString = "TextSample";
                txt.HorizontalMode = TextHorizontalMode.TextLeft;
                txt.VerticalMode = TextVerticalMode.TextTop;
                txt.TextStyle = objId;

                zcBlkTblRec.AppendEntity(txt);
                zcTrans.AddNewlyCreatedDBObject(txt, true);
                zcTrans.Commit();
            }
        }

        [CommandMethod("MTextSample")]
        static public void MTextSample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);

            using (Transaction zcTrans = db.TransactionManager.StartTransaction())
            {
                TextStyleTable zcTxtStyTbl = zcTrans.GetObject(db.TextStyleTableId, OpenMode.ForWrite) as TextStyleTable;
                string styleName = "Standard";
                ObjectId objId = new ObjectId();
                if (zcTxtStyTbl.Has(styleName))
                {
                    foreach (ObjectId id in zcTxtStyTbl)
                    {
                        TextStyleTableRecord strrec = (TextStyleTableRecord)zcTrans.GetObject(id, OpenMode.ForRead);
                        if (strrec.Name == "Standard")
                        {
                            objId = id;
                            break;
                        }
                    }
                }
                else
                {
                    return;
                }

                BlockTable zcBlkTbl = zcTrans.GetObject(db.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord zcBlkTblRec = zcTrans.GetObject(zcBlkTbl[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;

                MText mText = new MText();
                mText.Contents = "MTEXTSAMPLE";
                mText.Location = new Point3d(0, 100, 0);
                mText.TextHeight = 50;
                mText.Rotation = 0;
                mText.Attachment = AttachmentPoint.MiddleLeft;
                mText.Height = 100;
                mText.Width = 200;
                mText.TextStyleId = objId;

                zcBlkTblRec.AppendEntity(mText);
                zcTrans.AddNewlyCreatedDBObject(mText, true);
                zcTrans.Commit();
            }
        }

        [CommandMethod("TextStyleSample")]
        static public void TextStyleSample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                TextStyleTable TST = (TextStyleTable)trans.GetObject(db.TextStyleTableId, OpenMode.ForWrite);
                if (TST.Has("new TxtStyle")) // Get and modify the style if it exists
                {
                    foreach (ObjectId id in TST)
                    {
                        if (!id.IsErased)
                        {
                            TextStyleTableRecord textStyleTableRecord = (TextStyleTableRecord)trans.GetObject(id, OpenMode.ForWrite);
                            if (textStyleTableRecord.Name == "new TxtStyle")
                            {
                                textStyleTableRecord.Name = "Mod TxtStyle";
                                textStyleTableRecord.FileName = "simplex";
                                textStyleTableRecord.BigFontFileName = null;
                                textStyleTableRecord.TextSize = 5;
                            }
                        }
                    }
                }
                else // Create if the style does not exist
                {
                    TextStyleTableRecord TSTR = new TextStyleTableRecord();
                    TSTR.Name = "new TxtStyle";
                    TSTR.FileName = "txt";
                    TSTR.BigFontFileName = "GBCBIG";
                    TSTR.TextSize = 10;

                    TST.Add(TSTR);
                    trans.AddNewlyCreatedDBObject(TSTR, true);
                }

                trans.Commit();
            }
        }
    }
}
