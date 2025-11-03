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

[assembly: CommandClass(typeof(DrawOrder.Commands))]

namespace DrawOrder
{
    class Commands
    {
        void GetObjectCollection(string prompt, ObjectIdCollection objCol)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptSelectionOptions selectionOpts = new PromptSelectionOptions();
            selectionOpts.MessageForAdding = prompt;
            PromptSelectionResult proSelRes = ed.GetSelection(selectionOpts);
            if (proSelRes.Status != PromptStatus.OK)
            {
                return;
            }
            foreach (ObjectId objId in proSelRes.Value.GetObjectIds())
            {
                objCol.Add(objId);
            }
        }

        [CommandMethod("DraworderCSExample")]
        public void DraworderCSExample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            ObjectIdCollection objCol = new ObjectIdCollection();
            GetObjectCollection("\nSelect the entity(s) you want to change the draw order", objCol);
            if (objCol.Count == 0)
                return;

            PromptKeywordOptions kwordsOpts = new PromptKeywordOptions("\nInput Options");
            kwordsOpts.Keywords.Add("A", "A", "Above(A)", true, true);
            kwordsOpts.Keywords.Add("U", "U", "Below(U)", true, true);
            kwordsOpts.Keywords.Add("F", "F", "Top(F)", true, true);
            kwordsOpts.Keywords.Add("B", "B", "Bottom(B)", true, true);
            kwordsOpts.Keywords.Default = "B";
            PromptResult proRes = doc.Editor.GetKeywords(kwordsOpts);
            if (proRes.Status == PromptStatus.OK)
            {
                switch (proRes.StringResult)
                {
                    case "A":
                        ObjectIdCollection tarObjCol = new ObjectIdCollection();
                        GetObjectCollection("\nSelect the reference entity", tarObjCol);

                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            for (int i = tarObjCol.Count - 1; i >= 0; i--)
                            {
                                dot.MoveAbove(objCol, tarObjCol[i]);
                            }
                            trans.Commit();
                        }
                        break;
                    case "U":
                        ObjectIdCollection tarObjCol1 = new ObjectIdCollection();
                        GetObjectCollection("\nSelect the reference entity", tarObjCol1);

                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            foreach (ObjectId id in tarObjCol1)
                            {
                                dot.MoveBelow(objCol, id);
                            }
                            trans.Commit();
                        }
                        break;
                    case "F":
                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            dot.MoveToTop(objCol);
                            trans.Commit();
                        }
                        break;
                    case "B":
                        using (Transaction trans = db.TransactionManager.StartTransaction())
                        {
                            BlockTable bt = (BlockTable)trans.GetObject(db.BlockTableId, OpenMode.ForRead);
                            BlockTableRecord btr = (BlockTableRecord)trans.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForRead);
                            DrawOrderTable dot = (DrawOrderTable)trans.GetObject(btr.DrawOrderTableId, OpenMode.ForWrite);

                            dot.MoveToBottom(objCol);
                            trans.Commit();
                        }
                        break;
                }
            }
            else if (proRes.Status == PromptStatus.Cancel)
                return;
        }
    }
}
