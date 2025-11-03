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

[assembly: CommandClass(typeof(CircleJig.Commands))]

namespace CircleJig
{
    class Commands
    {
        [CommandMethod("CircleJig")]
        static public void CircleJig()
        {
            Database db = Application.DocumentManager.MdiActiveDocument.Database;
            Vector3d x = db.Ucsxdir;
            Vector3d y = db.Ucsydir;
            Vector3d NormalVec = x.CrossProduct(y);

            ZwSoft.ZwCAD.DatabaseServices.TransactionManager tm = db.TransactionManager;
            CDrawCircleJig cDrawCircleJig = new CDrawCircleJig(NormalVec);
            cDrawCircleJig.setPromptCount(0);
            Application.DocumentManager.MdiActiveDocument.Editor.Drag(cDrawCircleJig);
            cDrawCircleJig.setPromptCount(1);
            Application.DocumentManager.MdiActiveDocument.Editor.Drag(cDrawCircleJig);

            using (Transaction myT = tm.StartTransaction())
            {
                BlockTable bt = (BlockTable)tm.GetObject(db.BlockTableId, OpenMode.ForRead, false);
                BlockTableRecord btr = (BlockTableRecord)tm.GetObject(bt[BlockTableRecord.ModelSpace], OpenMode.ForWrite, false);
                btr.AppendEntity(cDrawCircleJig.GetEntity());
                tm.AddNewlyCreatedDBObject(cDrawCircleJig.GetEntity(), true);
                myT.Commit();
            }
        }
    }
}
