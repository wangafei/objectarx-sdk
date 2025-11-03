using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.Runtime;

namespace ObjOverrule
{
    class CPolyLineOverrule : ObjectOverrule
    {
        bool m_canCopy;
        public CPolyLineOverrule(bool canCopy)
        {
            m_canCopy = canCopy;
        }
        public override void Cancel(DBObject dbObject)
        {
            if (IsApplicable(dbObject))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                ed.WriteMessage("\n cancel polyline operation");
            }
            else
            {
                base.Cancel(dbObject);
            }
        }
        public override void Close(DBObject dbObject)
        {
            base.Close(dbObject);
        }
        public override DBObject DeepClone(DBObject dbObject, DBObject ownerObject, IdMapping idMap, bool isPrimary)
        {
            if (IsApplicable(dbObject))
            {
                DBObject dBObject = base.DeepClone(dbObject, ownerObject, idMap, isPrimary);
                if (dbObject != null && dbObject.GetType() == typeof(Polyline))
                {
                    Polyline pLine = dBObject as Polyline;
                    pLine.ColorIndex = 1;//System.Runtime.InteropServices.SEHException
                }
                return dBObject;
            }
            return base.DeepClone(dbObject, ownerObject, idMap, isPrimary);
        }
        public override void Erase(DBObject dbObject, bool erasing)
        {
            base.Erase(dbObject, erasing);
        }
        public override void Open(DBObject dbObject, OpenMode mode)
        {
            if (IsApplicable(dbObject))
            {
                Polyline pLine = dbObject as Polyline;
                if (pLine.IsWriteEnabled)
                    pLine.LineWeight = LineWeight.LineWeight020;
            }
            else
            {
                base.Open(dbObject, mode);
            }
        }
        public override DBObject WblockClone(DBObject dbObject, RXObject ownerObject, IdMapping idMap, bool isPrimary)
        {
            if (!m_canCopy && IsApplicable(dbObject))
            {
                Database db = HostApplicationServices.WorkingDatabase;
                Document doc = Application.DocumentManager.GetDocument(db);
                ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
                ed.WriteMessage("\n wblockclone polyline operation!(forbid copy)");
                return null;
            }
            return base.WblockClone(dbObject, ownerObject, idMap, isPrimary);
        }
        public override bool IsApplicable(RXObject overruledSubject)
        {
            return overruledSubject.GetType() == typeof(Polyline);
        }
    }
}
