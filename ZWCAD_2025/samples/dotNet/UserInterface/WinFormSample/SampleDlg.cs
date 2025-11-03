using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.EditorInput;
using Application = ZwSoft.ZwCAD.ApplicationServices.Application;

namespace WinFormSample
{
    public partial class SampleDlg : Form
    {
        public SampleDlg()
        {
            InitializeComponent();

            this.listView1.View = View.Details;
            this.listView1.FullRowSelect = true;
            this.listView1.Columns.Add("Field", this.listView1.Width /2);
            this.listView1.Columns.Add("Value", this.listView1.Width / 2);
        }

        private void AddSeperatorLine(string str)
        {
            ListViewItem listViewItem = new ListViewItem();
            listViewItem.Text = str;
            this.listView1.Items.Add(listViewItem);
        }

        private void AddToList(string field, string value)
        {
            ListViewItem listViewItem = new ListViewItem();
            listViewItem.Text = field;
            listViewItem.SubItems.Add(value);
            this.listView1.Items.Add(listViewItem);
        }

        private string GetEntLayerName(Entity ent)
        {
            if (ent == null)
            {
                return "null";
            }

            string layername = "null";
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                LayerTable lyrTbl = (LayerTable)trans.GetObject(db.LayerTableId, OpenMode.ForRead);
                LayerTableRecord lyrTblRec = (LayerTableRecord)trans.GetObject(ent.LayerId, OpenMode.ForRead);
                layername = lyrTblRec.Name;
                trans.Commit();
            }
            return layername;
        }

        private string GetEntColorName(Entity ent)
        {
            if (ent == null)
            {
                return "null";
            }

            int coloridx = ent.ColorIndex;
            string str;
            if (coloridx == 0)
                str = "ByBlock";
            else if (coloridx == 256)
                str = "ByLayer";
            else if (coloridx == 1)
                str = "1-Red";
            else if (coloridx == 2)
                str = "2-Yellow";
            else if (coloridx == 3)
                str = "3-Green";
            else if (coloridx == 4)
                str = "4-Cyan";
            else if (coloridx == 5)
                str = "5-Blue";
            else if (coloridx == 6)
                str = "6-Magenta";
            else if (coloridx == 7)
                str = "7-White";
            else
                str = ent.ColorIndex.ToString();

            return str;
        }

        private void DisplayCircle(Circle circle)
        {
            if (circle == null)
            {
                return;
            }

            AddSeperatorLine("------Circle------");
            string centerpt = circle.Center.ToString();
            string rad = circle.Radius.ToString();
            string thick = circle.Thickness.ToString();
            string nor = circle.Normal.ToString();
            AddToList("Center Pt", centerpt);
            AddToList("Radius", rad);
            AddToList("Thickness", thick);
            AddToList("Normal", nor);
            
        }

        private void DisplayCurve(Curve curve)
        {
            if (curve == null)
            {
                return;
            }

            AddSeperatorLine("------Curve------");
            string isclosed = curve.Closed.ToString();
            string isperiodic = curve.IsPeriodic.ToString();
            AddToList("Is Closed", isclosed);
            AddToList("Is Periodic", isclosed);

            Circle circle = curve as Circle;
            Line line = curve as Line;
            if (circle != null)
            {
                DisplayCircle(circle);
            }
            else if (line != null)
            {
                //TODO
            }
        }

        private void DisplayEntity(Entity ent)
        {
            if (ent == null)
            {
                return;
            }

            AddSeperatorLine("------Entity------");
            string layername = GetEntLayerName(ent);
            string colorname = GetEntColorName(ent);
            string blockname = ent.BlockName.ToString();
            AddToList("Layer Name", layername);
            AddToList("Color Name", colorname);
            AddToList("Block Name", blockname);

            Curve curve = ent as Curve;
            DBPoint dbpoint = ent as DBPoint;
            if (curve != null)
            {
                DisplayCurve(curve);
            }
            else if (dbpoint != null)
            {
                //TODO
            }
        }

        private void Display(DBObject obj)
        {
            if (obj == null)
            {
                return;
            }

            AddSeperatorLine("------DBObject------");
            string classname = obj.ToString();
            string entname = obj.ObjectId.ToString();
            string strhandle = obj.Handle.ToString();
            AddToList("Class Name", classname);
            AddToList("ObjectId Name", entname);
            AddToList("Handle", strhandle);

            Entity ent = obj as Entity;
            DBDictionary dict = obj as DBDictionary;
            if (ent != null)
            {
                DisplayEntity(ent);
            }
            else if (dict != null)
            {
                //TODO
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            this.Hide();

            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            ZwSoft.ZwCAD.EditorInput.Editor ed = doc.Editor;
            PromptEntityResult result = doc.Editor.GetEntity("\nSelect the entity");
            if (result.Status != PromptStatus.OK)
            {
                this.Show();
                return;
            }
            Transaction trans = doc.TransactionManager.StartTransaction();
            using (trans)
            {
                DBObject Object = trans.GetObject(result.ObjectId, OpenMode.ForRead);
                if( Object == null)
                {
                    this.Show();
                    return;
                }

                this.listView1.Items.Clear();
                Display(Object);

                trans.Commit();
            }

            this.Show();
        }
    }
}
