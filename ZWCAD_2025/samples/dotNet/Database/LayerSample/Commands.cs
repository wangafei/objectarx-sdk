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
using ZwSoft.ZwCAD.Colors;

[assembly: CommandClass(typeof(LayerSample.Commands))]

namespace LayerSample
{
    class Commands
    {
        [CommandMethod("LayerSample")]
        static public void LayerSample()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                LayerTable lyrTbl = (LayerTable)trans.GetObject(db.LayerTableId, OpenMode.ForRead);
                if (lyrTbl.Has("Layer 1"))
                {
                    foreach (ObjectId id in lyrTbl)
                    {
                        if (!id.IsErased)
                        {
                            LayerTableRecord lyrTblRec = (LayerTableRecord)trans.GetObject(id, OpenMode.ForWrite);
                            if (lyrTblRec.Name == "Layer 1")
                            {
                                lyrTblRec.Name = "Layer 2";
                                lyrTblRec.IsOff = false;
                                lyrTblRec.IsFrozen = false;
                                lyrTblRec.IsLocked = false;
                                Color color = new Color();
                                color.SetRgb(0, 255, 0);
                                lyrTblRec.Color = color;
                                lyrTblRec.ViewportVisibilityDefault = false;
                                Byte trParByte = 127;
                                Transparency transparency = new Transparency(trParByte);
                                lyrTblRec.Transparency = transparency;
                            }
                        }
                    }
                }
                else
                {
                    LayerTableRecord lyrTblRec = new LayerTableRecord();
                    lyrTblRec.Name = "Layer 1";
                    lyrTblRec.IsOff = true;
                    lyrTblRec.IsFrozen = true;
                    lyrTblRec.IsLocked = true;
                    Color color = new Color();
                    color.SetRgb(255, 0, 0);
                    lyrTblRec.Color = color;
                    lyrTblRec.ViewportVisibilityDefault = true;
                    Transparency transparency = new Transparency(TransparencyMethod.ByLayer);
                    lyrTblRec.Transparency = transparency;
                    lyrTbl.UpgradeOpen();
                    lyrTbl.Add(lyrTblRec);
                    trans.AddNewlyCreatedDBObject(lyrTblRec, true);
                }
                trans.Commit();
            }
        }
    }
}
