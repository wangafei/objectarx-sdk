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

[assembly: CommandClass(typeof(MakeHatch.Commands))]

namespace MakeHatch
{
    class Commands
    {
        // Simple hatch sample: Draw three concentric circles and execute "TestCreateHatch"
        //
        [CommandMethod("TestCreateHatch")]
        static public void TestCreateHatch()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                BlockTable blkTbl = trans.GetObject(db.BlockTableId, OpenMode.ForRead) as BlockTable;
                BlockTableRecord blkTblRec = trans.GetObject(blkTbl[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;

                PromptSelectionResult selRes = ed.GetSelection();
                if (selRes.Status != PromptStatus.OK)
                    return;
                SelectionSet sSet = selRes.Value;
                ObjectId[] objIds = sSet.GetObjectIds();

                Dictionary<ObjectId, double> dic1 = new Dictionary<ObjectId, double>();
                foreach (ObjectId id in objIds)
                {
                    Entity entity = (Entity)id.GetObject(OpenMode.ForWrite);
                    dic1.Add(id, ((Curve)entity).Area);
                }
                Dictionary<ObjectId, double> dic2 = dic1.OrderBy(o => o.Value).ToDictionary(k => k.Key, v => v.Value);

                using (Hatch hatch = new Hatch())
                {
                    blkTblRec.AppendEntity(hatch);
                    trans.AddNewlyCreatedDBObject(hatch, true);

                    hatch.Normal = Vector3d.ZAxis;
                    hatch.Elevation = 0.0;
                    hatch.Associative = true;
                    hatch.SetHatchPattern(HatchPatternType.PreDefined, "SOLID");

                    PromptKeywordOptions keyOpts = new PromptKeywordOptions("");
                    keyOpts.Message = "Style type [Normal(N)/Outer(O)/Ignore(I)]:";
                    keyOpts.Keywords.Add("N");
                    keyOpts.Keywords.Add("O");
                    keyOpts.Keywords.Add("I");
                    keyOpts.AllowNone = false;

                    PromptResult keyRes = doc.Editor.GetKeywords(keyOpts);
                    if (keyRes.StringResult == "N")
                        hatch.HatchStyle = HatchStyle.Normal;
                    else if (keyRes.StringResult == "O")
                        hatch.HatchStyle = HatchStyle.Outer;
                    else if (keyRes.StringResult == "I")
                        hatch.HatchStyle = HatchStyle.Ignore;

                    int nDep = 0;
                    foreach (KeyValuePair<ObjectId, double> item in dic2)
                    {
                        if (nDep == dic2.Count - 1)
                        {
                            ObjectIdCollection externalIdColl = new ObjectIdCollection();
                            externalIdColl.Add(item.Key);
                            hatch.AppendLoop(HatchLoopTypes.External, externalIdColl);
                        }
                        else if (nDep == dic2.Count - 2)
                        {
                            ObjectIdCollection outerMostIdColl = new ObjectIdCollection();
                            outerMostIdColl.Add(item.Key);
                            hatch.AppendLoop(HatchLoopTypes.Outermost, outerMostIdColl);
                        }
                        else
                        {
                            ObjectIdCollection defaultIdColl = new ObjectIdCollection();
                            defaultIdColl.Add(item.Key);
                            hatch.AppendLoop(HatchLoopTypes.Default, defaultIdColl);
                        }
                        nDep++;
                    }

                    hatch.EvaluateHatch(true);
                }
                trans.Commit();
            }
        }
    }
}
