using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZwSoft.ZwCAD.ApplicationServices;
using ZwSoft.ZwCAD.DatabaseServices;
using ZwSoft.ZwCAD.PlottingServices;
using Application = ZwSoft.ZwCAD.ApplicationServices.Application;
using PlotType = ZwSoft.ZwCAD.DatabaseServices.PlotType;

namespace PlotSample
{
    public partial class SampleDlg : Form
    {
        PlotSettingsValidator pPSV;
        PlotSettings plotsettings;
        ObjectId layId;
        CustomScale scale;

        private void RefreshDeviceName()
        {
            StringCollection devicestrcoll = pPSV.GetPlotDeviceList();
            for (int i = 0; i < devicestrcoll.Count; i++)
            {
                string str = devicestrcoll[i];
                this.comboBox_Device.Items.Add(str);
            }
            string strtemp = devicestrcoll[0];
            this.comboBox_Device.SelectedItem = strtemp;
        }

        private void RefreshMediaName()
        {
            StringCollection mediastrcoll = pPSV.GetCanonicalMediaNameList(plotsettings);
            this.comboBox_Media.Items.Clear();
            for (int i = 0; i < mediastrcoll.Count; i++)
            {
                string str = mediastrcoll[i];
                this.comboBox_Media.Items.Add(str);
            }
            string strtemp = plotsettings.CanonicalMediaName;
            this.comboBox_Media.SelectedItem = strtemp;
        }

        private void RefreshPlotStyleName()
        {
            StringCollection plotstylestrcoll = pPSV.GetPlotStyleSheetList();
            for (int i = 0; i < plotstylestrcoll.Count; i++)
            {
                string str = plotstylestrcoll[i];
                this.comboBox_PlotStyle.Items.Add(str);
            }
            string strtemp = plotstylestrcoll[0];
            this.comboBox_PlotStyle.SelectedItem = strtemp;
        }

        private void CalcExtents()
        {
            if (this.checkBox_Fit.Checked)
            {
                this.textBox_Scale.Enabled = false;
                pPSV.SetUseStandardScale(plotsettings, true);
                pPSV.SetStdScaleType(plotsettings, StdScaleType.ScaleToFit);
                pPSV.SetPlotType(plotsettings, PlotType.Extents);
                pPSV.SetPlotCentered(plotsettings, true);
                scale = plotsettings.CustomPrintScale;
                this.textBox_Scale.Text = (scale.Numerator/scale.Denominator).ToString("f2");
            }
            else
            {
                this.textBox_Scale.Enabled = true;
            }
        }

        public SampleDlg()
        {
            InitializeComponent();

            pPSV = PlotSettingsValidator.Current;
            Database db = HostApplicationServices.WorkingDatabase;
            Document doc = Application.DocumentManager.GetDocument(db);
            using (Transaction trans = db.TransactionManager.StartTransaction())
            {
                ObjectId Id = LayoutManager.Current.GetLayoutId(LayoutManager.Current.CurrentLayout);
                Layout lay = (Layout)trans.GetObject(Id, OpenMode.ForRead);
                layId = lay.ObjectId;
                plotsettings = new PlotSettings(lay.ModelType);
                plotsettings.CopyFrom(lay);
                trans.Commit();
            }

            // Control Initialization
            this.checkBox_Fit.Checked = true;
            this.textBox_Scale.Enabled = false;

            string filename = System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "\\NetPlot.pdf";
            this.textBox_FileName.Text = filename;
            this.textBox_FileName.Enabled = false;
            this.checkBox_PlotToFile.Checked = false;

            //landscape = false;
            this.checkBox_LandScape.Checked = false;
            pPSV.SetPlotRotation(plotsettings, PlotRotation.Degrees000);

            int backplot = Convert.ToInt32(Application.GetSystemVariable("BACKGROUNDPLOT"));
            if (backplot == 1 || backplot == 3)
            {
                this.checkBox_BackGround.Checked = true;
            }
            else
            {
                this.checkBox_BackGround.Checked = false;
            }

            // Initialize the value of the devices
            RefreshDeviceName();
            // Initialize the value of the styles
            RefreshPlotStyleName();
            // Calculate the page scale
            CalcExtents();
        }

        private void comboBox_Device_SelectedIndexChanged(object sender, EventArgs e)
        {
            string currentdevice = Convert.ToString(this.comboBox_Device.SelectedItem);
            pPSV.SetPlotConfigurationName(plotsettings, currentdevice, null);
            pPSV.RefreshLists(plotsettings);

            // Refresh the media list
            RefreshMediaName();
            if (this.checkBox_Fit.Checked)
                CalcExtents();

            PlotConfig plotConfig;
            plotConfig = PlotConfigManager.SetCurrentConfig(currentdevice);
            if (plotConfig.PlotToFileCapability != PlotToFileCapability.PlotToFileAllowed)
            {
                if (plotConfig.PlotToFileCapability == PlotToFileCapability.NoPlotToFile)
                {
                    this.checkBox_PlotToFile.Checked = false;
                    this.textBox_FileName.Enabled = false;
                }
                else if (this.checkBox_PlotToFile.Checked)
                {
                    this.textBox_FileName.Enabled = true;
                }
            }
            else if(this.checkBox_PlotToFile.Checked)
            {
                this.textBox_FileName.Enabled = true;
            }
        }

        private void comboBox_Media_SelectedIndexChanged(object sender, EventArgs e)
        {
            string media = this.comboBox_Media.SelectedItem.ToString();
            pPSV.SetCanonicalMediaName(plotsettings, media);
            if (this.checkBox_Fit.Checked)
            {
                CalcExtents();
            }
        }

        private void textBox_Scale_Keypress(object sender, KeyPressEventArgs e)
        {
            // If the input is not backspace and cannot be converted to decimal, the input is masked.
            if (!(e.KeyChar == '\b' || float.TryParse(((TextBox)sender).Text + e.KeyChar.ToString(), out float f)))
            {
                e.Handled = true;
            }
        }

        private void button_Preview_Click(object sender, EventArgs e)
        {
            try
            {
                this.Hide();

                pPSV.SetPlotType(plotsettings, PlotType.Extents);
                if (this.checkBox_Fit.Checked)
                {
                    pPSV.SetUseStandardScale(plotsettings, true);
                    pPSV.SetStdScaleType(plotsettings, StdScaleType.ScaleToFit);
                }
                else
                {
                    double curscale = System.Convert.ToDouble(this.textBox_Scale.Text);
                    scale = new CustomScale(1, curscale);
                    pPSV.SetUseStandardScale(plotsettings, false);
                    pPSV.SetCustomPrintScale(plotsettings, scale);
                }
                pPSV.SetPlotCentered(plotsettings, true);

                string curplotstyle = this.comboBox_PlotStyle.SelectedItem.ToString();
                pPSV.SetCurrentStyleSheet(plotsettings, curplotstyle);

                PlotEngine plotEngine = PlotFactory.CreatePreviewEngine((Int32)PreviewEngineFlags.Plot);
                using (plotEngine)
                {
                    plotEngine.BeginPlot(null, null);

                    PlotInfo plotInfo = new PlotInfo();
                    plotInfo.Layout = layId;
                    plotInfo.OverrideSettings = plotsettings;
                    PlotInfoValidator infoValidator = new PlotInfoValidator();
                    infoValidator.MediaMatchingPolicy = MatchingPolicy.MatchEnabled;
                    infoValidator.Validate(plotInfo);

                    string docname = Application.DocumentManager.MdiActiveDocument.Name;
                    string filename = this.textBox_FileName.Text;
                    if (this.checkBox_PlotToFile.Checked)
                    {
                        plotEngine.BeginDocument(plotInfo, docname, null, 1, true, filename);
                    }
                    else
                    {
                        plotEngine.BeginDocument(plotInfo, docname, null, 1, false, null);
                    }

                    PlotPageInfo pageInfo = new PlotPageInfo();
                    plotEngine.BeginPage(pageInfo, plotInfo, true, null);
                    plotEngine.BeginGenerateGraphics(null);
                    plotEngine.EndGenerateGraphics(null);
                    plotEngine.EndPage(null);
                    plotEngine.EndDocument(null);
                    plotEngine.EndPlot(null);
                }
            }
            catch (Exception ex)
            {
                string strErr = "Some exception has been caught!\nException: " + ex.Message;
                MessageBox.Show(strErr, "Warning");
            }
            finally
            {
                this.Show();
            }
        }

        private void button_Plot_Click(object sender, EventArgs e)
        {
            string filename = this.textBox_FileName.Text;
            string filepath = filename.Substring(0, filename.LastIndexOf('\\'));
            if (!System.IO.Directory.Exists(filepath))
            {
                MessageBox.Show("Invalid file path！", "Warning");
                return;
            }

            pPSV.SetPlotType(plotsettings, PlotType.Extents);
            if (this.checkBox_Fit.Checked)
            {
                pPSV.SetUseStandardScale(plotsettings, true);
                pPSV.SetStdScaleType(plotsettings, StdScaleType.ScaleToFit);
            }
            else
            {
                double curscale = System.Convert.ToDouble(this.textBox_Scale.Text);
                scale = new CustomScale(1, curscale);
                pPSV.SetUseStandardScale(plotsettings, false);
                pPSV.SetCustomPrintScale(plotsettings, scale);
            }
            pPSV.SetPlotCentered(plotsettings, true);

            string curplotstyle = this.comboBox_PlotStyle.SelectedItem.ToString();
            pPSV.SetCurrentStyleSheet(plotsettings, curplotstyle);

            PlotEngine plotEngine = PlotFactory.CreatePublishEngine();
            using (plotEngine)
            {
                plotEngine.BeginPlot(null, null);

                PlotInfo plotInfo = new PlotInfo();
                plotInfo.Layout = layId;
                plotInfo.OverrideSettings = plotsettings;
                PlotInfoValidator infoValidator = new PlotInfoValidator();
                infoValidator.MediaMatchingPolicy = MatchingPolicy.MatchEnabled;
                infoValidator.Validate(plotInfo);

                string docname = Application.DocumentManager.MdiActiveDocument.Name;

                if (this.checkBox_PlotToFile.Checked)
                {
                    plotEngine.BeginDocument(plotInfo, docname, null, 1, true, filename);
                }
                else
                {
                    plotEngine.BeginDocument(plotInfo, docname, null, 1, false, null);
                }

                PlotPageInfo pageInfo = new PlotPageInfo();
                plotEngine.BeginPage(pageInfo, plotInfo, true, null);
                plotEngine.BeginGenerateGraphics(null);
                plotEngine.EndGenerateGraphics(null);
                plotEngine.EndPage(null);
                plotEngine.EndDocument(null);
                plotEngine.EndPlot(null);
            }
        }

        private void checkBox_PlotToFile_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBox_PlotToFile.Checked)
            {
                this.textBox_FileName.Enabled = true;
            }
            else
            {
                this.textBox_FileName.Enabled = false;
            }
        }

        private void checkBox_LandScape_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBox_LandScape.Checked)
            {
                pPSV.SetPlotRotation(plotsettings, PlotRotation.Degrees090);
            }
            else
            {
                pPSV.SetPlotRotation(plotsettings, PlotRotation.Degrees000);
            }
        }
        
        private void checkBox_BackGround_CheckedChanged(object sender, EventArgs e)
        {
            if (this.checkBox_BackGround.Checked)
            {
                Application.SetSystemVariable("BACKGROUNDPLOT", 1);
            }
            else
            {
                Application.SetSystemVariable("BACKGROUNDPLOT", 0);
            }
        }

        private void checkBox_Fit_CheckedChanged(object sender, EventArgs e)
        {
            CalcExtents();
        }
    }
}
