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

[assembly: CommandClass(typeof(Interaction.Commands))]

namespace Interaction
{
    class Commands
    {
        /// <summary>
        /// Editor.Getxxx()
        /// </summary>
        [CommandMethod("TestGetPoint")]
        public void TestGetPoint()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;

            PromptPointOptions ptOpts = new PromptPointOptions("Select a Point");
            ptOpts.BasePoint = new Point3d(0, 0, 0);
            ptOpts.UseDashedLine = true;
            //ptOpts.Message = "Select a Point";

            PromptPointResult ptRes = ed.GetPoint(ptOpts);
            Point3d pt = ptRes.Value;

            if (ptRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("\nThe Point is ({0}, {1}, {2})", pt.X, pt.Y, pt.Z);
            }
            else if (ptRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + ptRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetString")]
        public void TestGetString()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptStringOptions strOpts = new PromptStringOptions("Input a string: ");
            strOpts.AllowSpaces = false;     //The Space is not allowed
            PromptResult strRes = ed.GetString(strOpts);
            if (strRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("The string is " + strRes.StringResult);
            }
            else if (strRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + strRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetAngle")]
        public void TestGetAngle()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptAngleOptions angOpts = new PromptAngleOptions("Pick the first point");
            angOpts.AllowNone = false;
            angOpts.UseDashedLine = true;
            PromptDoubleResult dblRes = ed.GetAngle(angOpts);

            if (dblRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("\nThe angle is {0}", dblRes.Value);
            }
            else if (dblRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + dblRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetInteger")]
        public void TestGetInteger()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptIntegerOptions intOpts = new PromptIntegerOptions("Input a Integer:");
            intOpts.AllowNegative = false;
            intOpts.AllowNone = false;
            intOpts.AllowZero = false;
            intOpts.DefaultValue = 100;
            PromptIntegerResult IntRes = ed.GetInteger(intOpts);
            if (IntRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("\nThe Integer is {0}", IntRes.Value);
            }
            else if (IntRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + IntRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetDouble")]
        public void TestGetDouble()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptDoubleOptions dblOpts = new PromptDoubleOptions("Input a real number");

            dblOpts.AllowNone = false;
            dblOpts.AllowZero = false;
            dblOpts.DefaultValue = 0.0;

            PromptDoubleResult dblRes = ed.GetDouble(dblOpts);
            if (dblRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("\nThe real number is {0}", dblRes.Value);
            }
            else if (dblRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + dblRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetCorner")]
        public void TestGetCorner()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;

            Point3d ptBase = new Point3d(0, 0, 0);
            PromptCornerOptions corOpts = new PromptCornerOptions("Pick the corner:", ptBase);

            PromptPointResult ptRes = ed.GetCorner(corOpts);
            if (ptRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("\nThe Corner Point is ({0}, {1}, {2})", ptRes.Value.X, ptRes.Value.Y, ptRes.Value.Z);
            }
            else if (ptRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + ptRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetDistance")]
        public void TestGetDistance()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptDistanceOptions DistOpts = new PromptDistanceOptions("Pick First Point");

            DistOpts.AllowNegative = false;
            DistOpts.AllowZero = false;
            DistOpts.AllowNone = false;
            DistOpts.UseDashedLine = true;

            PromptDoubleResult dblRes = ed.GetDistance(DistOpts);

            if (dblRes.Status == PromptStatus.OK)
            {
                ed.WriteMessage("\nThe distance is {0}", dblRes.Value);
            }
            else if (dblRes.Status == PromptStatus.Cancel)
            {
                ed.WriteMessage("\nYou have cancelled!");
            }
            else
            {
                ed.WriteMessage("\nOther status: " + dblRes.Status.ToString());
            }
        }

        [CommandMethod("TestGetKeyWord")]
        public void TestGetKeyWord()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;

            PromptKeywordOptions kwOpts = new PromptKeywordOptions("Input KeyWord ");

            kwOpts.Keywords.Add("A", "A", "Branch A(A)", true, true);
            kwOpts.Keywords.Add("B", "B", "Branch B(B)", true, true);
            kwOpts.Keywords.Add("C", "C", "Branch C(C)", true, true);
            kwOpts.Keywords.Add("D", "D", "Branch D(D)", true, true);
            kwOpts.Keywords.Default = "D";

            PromptResult kwordRes = ed.GetKeywords(kwOpts);

            if (kwordRes.Status == PromptStatus.OK)
            {
                switch (kwordRes.StringResult)
                {
                    case "A":
                        ed.WriteMessage("This is Branch A");
                        break;
                    case "B":
                        ed.WriteMessage("This is Branch B");
                        break;
                    case "C":
                        ed.WriteMessage("This is Branch C");
                        break;
                    case "D":
                        ed.WriteMessage("This is Branch D");
                        break;
                }
            }
            else
            {
                ed.WriteMessage("Other Status: " + kwordRes.Status.ToString());
            }
        }

        /// <summary>
        /// Editor.GetEntity()
        /// </summary>

        [CommandMethod("EntSelTest")]
        static public void EntSelTest()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;

            PromptEntityOptions entOpts = new PromptEntityOptions("Select an Entity");
            PromptEntityResult entRes = entRes = ed.GetEntity(entOpts);

            if (entRes.Status == PromptStatus.OK)
            {
                ObjectId objId = entRes.ObjectId;
                ZwSoft.ZwCAD.DatabaseServices.TransactionManager trManager = db.TransactionManager;
                using (Transaction trans = trManager.StartTransaction())
                {
                    Entity entity = (Entity)trans.GetObject(objId, OpenMode.ForRead, true);
                    ed.WriteMessage("\nThe Entity you select is " + entity.GetType().FullName);
                    trans.Commit();
                }
            }
        }

        /// <summary>
        /// Editor.GetSelection()
        /// </summary>

        static public void ChangeColor(ObjectId[] objIds)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                foreach (ObjectId objId in objIds)
                {
                    Entity entity = (Entity)objId.GetObject(OpenMode.ForWrite);

                    if (entity.GetType() == typeof(Line) || entity.GetType() == typeof(Circle))
                        entity.ColorIndex = 5;
                }
                trans.Commit();
            }
        }

        [CommandMethod("Select_GetSelection")]
        static public void GetSelectionTest()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.MessageForAdding = "Select some entities: ";

            TypedValue[] values = { new TypedValue(0, "LINE"), new TypedValue(62, 1) };
            SelectionFilter filter = new SelectionFilter(values);

            PromptSelectionResult selRes = ed.GetSelection(selOpts, filter);
            //PromptSelectionResult selRes = ed.GetSelection();     //no prompt
            //PromptSelectionResult selRes = ed.GetSelection(selOpts);  //prompt, but no filter
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();
            ChangeColor(objIds);

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
        }

        [CommandMethod("Select_KeywordSelection")]
        static public void SelectKeywordSelection()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.MessageForAdding = "Select some entities: ";
            selOpts.Keywords.Add("A");
            selOpts.Keywords.Add("B");
            selOpts.Keywords.Add("C");

            selOpts.KeywordInput += new SelectionTextInputEventHandler(selOptsCallBack);
            PromptSelectionResult selRes = ed.GetSelection(selOpts);
            selOpts.KeywordInput -= new SelectionTextInputEventHandler(selOptsCallBack);

            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
        }

        static void selOptsCallBack(object sender, SelectionTextInputEventArgs e)
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;
            if (e.Input.CompareTo("A") == 0)
            {
                ed.WriteMessage("Keyword A");
            }
            else if (e.Input.CompareTo("B") == 0)
            {
                ed.WriteMessage("Keyword B");
            }
            else if (e.Input.CompareTo("C") == 0)
            {
                ed.WriteMessage("Keyword C");
            }
        }

        // All in the database
        [CommandMethod("Select_All")]
        static public void SelectAll()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionResult selRes = ed.SelectAll();
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
        }

        [CommandMethod("Select_Fence")]
        static public void SelectFence()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            Point3d[] pt3dArr = new Point3d[5];
            pt3dArr[0] = new Point3d(0, 0, 0);
            pt3dArr[1] = new Point3d(1000, 0, 0);
            pt3dArr[2] = new Point3d(1000, 1500, 0);
            pt3dArr[3] = new Point3d(0, 1000, 0);
            pt3dArr[4] = new Point3d(0, 0, 0);

            Point3dCollection pt3dCol = new Point3dCollection(pt3dArr);

            PromptSelectionResult selRes = ed.SelectFence(pt3dCol);
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
        }

        [CommandMethod("Select_Single")]
        static public void SelectSingle()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionOptions selOpts = new PromptSelectionOptions();
            selOpts.SingleOnly = true;

            PromptSelectionResult selRes = ed.GetSelection();
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
            ChangeColor(objIds);
        }

        [CommandMethod("Select_Window")]
        static public void SelectWindow()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionResult selRes = ed.SelectWindow(new Point3d(0, 0, 0), new Point3d(1000, 1000, 0));
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
            ChangeColor(objIds);
        }

        [CommandMethod("Select_CrossingWindow")]
        static public void SelectCrossingWindow()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionResult selRes = ed.SelectCrossingWindow(new Point3d(0, 0, 0), new Point3d(1000, 1000, 0));
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
            ChangeColor(objIds);
        }

        [CommandMethod("Select_CrossingPolygon")]
        static public void SelectCrossingPolygon()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            Point3d[] pt3dArr = new Point3d[5];
            pt3dArr[0] = new Point3d(0, 0, 0);
            pt3dArr[1] = new Point3d(1000, 0, 0);
            pt3dArr[2] = new Point3d(1000, 1500, 0);
            pt3dArr[3] = new Point3d(0, 1000, 0);
            pt3dArr[4] = new Point3d(0, 0, 0);

            Point3dCollection pt3dCol = new Point3dCollection(pt3dArr);

            PromptSelectionResult selRes = ed.SelectCrossingPolygon(pt3dCol);
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
            ChangeColor(objIds);
        }

        [CommandMethod("Select_Implied", CommandFlags.UsePickSet)]
        static public void SelectImplied()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            PromptSelectionResult selRes = ed.SelectImplied();
            if (selRes.Status != PromptStatus.OK)
                return;

            SelectionSet sSet = selRes.Value;
            ObjectId[] objIds = sSet.GetObjectIds();

            ed.WriteMessage("\nThe selection set has {0} object", objIds.Length);
            ChangeColor(objIds);
        }

        // You can press F1 to query various system variables and their preset values in the help file
        public static Dictionary<string, object> oldSysVar = new Dictionary<string, object>();

        [CommandMethod("SetSysVarInt")]
        static public void SetSysVarInt()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            object obj = Application.GetSystemVariable("CURSORSIZE");
            if (!oldSysVar.ContainsKey("CURSORSIZE"))
                oldSysVar.Add("CURSORSIZE", obj);

            PromptIntegerOptions intOpts = new PromptIntegerOptions("Set cursor size(Integer 1-100)");
            intOpts.AllowNegative = false;
            intOpts.AllowZero = false;
            intOpts.AllowNone = false;

            PromptIntegerResult IntRes = ed.GetInteger(intOpts);
            if (IntRes.Status == PromptStatus.OK)
            {
                Application.SetSystemVariable("CURSORSIZE", IntRes.Value);
            }
        }
        [CommandMethod("GetSysVarInt")]
        static public void GetSysVarInt()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            int nRet = Convert.ToInt32(Application.GetSystemVariable("CURSORSIZE"));
            ed.WriteMessage("CURSORSIZE = {0}", nRet);
        }

        [CommandMethod("SetSysVarStr")]
        static public void SetSysVarStr()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            object obj = Application.GetSystemVariable("CECOLOR");
            if (!oldSysVar.ContainsKey("CECOLOR"))
                oldSysVar.Add("CECOLOR", obj);

            PromptStringOptions strOpts = new PromptStringOptions("Set Color(BYLAYER/BYBLOCK/1-255)");
            strOpts.AllowSpaces = false;

            PromptResult StrRes = ed.GetString(strOpts);
            if (StrRes.Status == PromptStatus.OK)
            {
                Application.SetSystemVariable("CECOLOR", StrRes.StringResult);
            }
        }
        [CommandMethod("GetSysVarStr")]
        static public void GetSysVarStr()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            string strRet = Convert.ToString(Application.GetSystemVariable("CECOLOR"));
            ed.WriteMessage("CECOLOR = {0}", strRet);
        }

        [CommandMethod("SetSysVarReal")]
        static public void SetSysVarReal()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            object obj = Application.GetSystemVariable("CIRCLERAD");
            if (!oldSysVar.ContainsKey("CIRCLERAD"))
                oldSysVar.Add("CIRCLERAD", obj);

            PromptDoubleOptions DblOpts = new PromptDoubleOptions("Set the default radius of circle(real number)");
            DblOpts.AllowNegative = false;
            DblOpts.AllowNone = false;

            PromptDoubleResult DblRes = ed.GetDouble(DblOpts);
            if (DblRes.Status == PromptStatus.OK)
            {
                Application.SetSystemVariable("CIRCLERAD", DblRes.Value);
            }
        }
        [CommandMethod("GetSysVarReal")]
        static public void GetSysVarReal()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            double dblRet = Convert.ToDouble(Application.GetSystemVariable("CIRCLERAD"));
            ed.WriteMessage("CIRCLERAD = {0}", dblRet);
        }

        [CommandMethod("GetSysVarPoint")]
        static public void GetSysVarPoint()
        {
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            Editor ed = doc.Editor;

            Point3d pt3d = (Point3d)Application.GetSystemVariable("VIEWCTR");
            ed.WriteMessage("VIEWCTR = ({0}, {1}, {2})", pt3d.X, pt3d.Y, pt3d.Z);
        }

        [CommandMethod("resetSysVar")]
        static public void resetSysVar()
        {
            foreach (var item in oldSysVar)
            {
                Application.SetSystemVariable(item.Key, item.Value);
            }
        }
    }
}
