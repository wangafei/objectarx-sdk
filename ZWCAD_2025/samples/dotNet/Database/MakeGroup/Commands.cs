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
using System.Windows.Forms;
using Application = ZwSoft.ZwCAD.ApplicationServices.Application;

[assembly: CommandClass(typeof(MakeGroup.Commands))]

namespace MakeGroup
{
    class Commands
    {
        [CommandMethod("GroupTest")]
        static public void GroupTest()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            bool bIsAnonymous = false;
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            bIsAnonymous = MessageBox.Show("Create a anonymous group?", "ZWCAD", buttons) == System.Windows.Forms.DialogResult.Yes;
            string szGroupName = bIsAnonymous ? "*" : null;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                DBDictionary groupDict;
                groupDict = trans.GetObject(db.GroupDictionaryId, OpenMode.ForWrite, true) as DBDictionary;

                if (!bIsAnonymous)
                {
                    PromptStringOptions strOpts = new PromptStringOptions("Enter group name:");
                    strOpts.AllowSpaces = false;

                    PromptResult strRet = ed.GetString(strOpts);
                    if (strRet.Status == PromptStatus.OK)
                    {
                        if (groupDict.Contains(strRet.StringResult))
                        {
                            ed.WriteMessage("\nThe group already exist!");
                            return;
                        }
                        szGroupName = strRet.StringResult;
                    }
                }

                PromptSelectionOptions selOpts = new PromptSelectionOptions();
                selOpts.MessageForAdding = "Select some entities:";
                PromptSelectionResult selRet = ed.GetSelection(selOpts);
                if (selRet.Status != PromptStatus.OK)
                {
                    ed.WriteMessage("\nNo entity!");
                    return;
                }

                SelectionSet sSet = selRet.Value;
                ObjectId[] objIds = sSet.GetObjectIds();

                Group group = new Group();
                group.Description = bIsAnonymous ? "This is a anonymous group" : "This is a normal group";
                groupDict.SetAt(szGroupName, group);

                foreach (ObjectId id in objIds)
                {
                    group.Append(id);
                }

                if (bIsAnonymous)
                {
                    group.SetAnonymous();
                }

                trans.AddNewlyCreatedDBObject(group, true);
                trans.Commit();
            }
        }

        [CommandMethod("UnGroupTest")]
        static public void UnGroupTest()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.MessageForAdding = "Select some entities:";
            PromptSelectionResult selRet = ed.GetSelection(selOpts);
            if (selRet.Status != PromptStatus.OK)
            {
                ed.WriteMessage("\nNo entity!");
                return;
            }
            SelectionSet sSet = selRet.Value;
            ObjectId[] objIds = sSet.GetObjectIds();


            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                DBDictionary groupDict;
                groupDict = trans.GetObject(db.GroupDictionaryId, OpenMode.ForWrite, true) as DBDictionary;

                HashSet<ObjectId> groupIdSet = new HashSet<ObjectId>();
                HashSet<ObjectId> groupEraseSet = new HashSet<ObjectId>();
                foreach (DBDictionaryEntry entry in groupDict)
                {
                    groupIdSet.Add(entry.Value);
                }

                foreach (ObjectId id in objIds)
                {
                    int nEntNum = 0;
                    ObjectId groupEraseId = ObjectId.Null;
                    Entity ent = trans.GetObject(id, OpenMode.ForWrite) as Entity;
                    foreach (ObjectId groupId in groupIdSet)
                    {
                        Group group = trans.GetObject(groupId, OpenMode.ForRead) as Group;
                        if (group.Has(ent) && group.NumEntities > nEntNum)
                        {
                            nEntNum = group.NumEntities;
                            groupEraseId = group.ObjectId;
                        }
                    }
                    if (groupEraseId.IsValid)
                    {
                        groupEraseSet.Add(groupEraseId);
                    }
                }

                foreach (ObjectId id in groupEraseSet)
                {
                    Group group = trans.GetObject(id, OpenMode.ForWrite) as Group;
                    group.Erase();
                }

                trans.Commit();
            }
        }
    }
}
