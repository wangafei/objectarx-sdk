namespace PlotSample
{
    partial class SampleDlg
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.comboBox_Device = new System.Windows.Forms.ComboBox();
            this.comboBox_Media = new System.Windows.Forms.ComboBox();
            this.comboBox_PlotStyle = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.checkBox_LandScape = new System.Windows.Forms.CheckBox();
            this.checkBox_BackGround = new System.Windows.Forms.CheckBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.textBox_Scale = new System.Windows.Forms.TextBox();
            this.checkBox_Fit = new System.Windows.Forms.CheckBox();
            this.textBox_FileName = new System.Windows.Forms.TextBox();
            this.checkBox_PlotToFile = new System.Windows.Forms.CheckBox();
            this.button_Preview = new System.Windows.Forms.Button();
            this.button_Plot = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // comboBox_Device
            // 
            this.comboBox_Device.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_Device.FormattingEnabled = true;
            this.comboBox_Device.Location = new System.Drawing.Point(135, 25);
            this.comboBox_Device.Name = "comboBox_Device";
            this.comboBox_Device.Size = new System.Drawing.Size(260, 20);
            this.comboBox_Device.TabIndex = 0;
            this.comboBox_Device.SelectedIndexChanged += new System.EventHandler(this.comboBox_Device_SelectedIndexChanged);
            // 
            // comboBox_Media
            // 
            this.comboBox_Media.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_Media.FormattingEnabled = true;
            this.comboBox_Media.Location = new System.Drawing.Point(135, 65);
            this.comboBox_Media.Name = "comboBox_Media";
            this.comboBox_Media.Size = new System.Drawing.Size(260, 20);
            this.comboBox_Media.TabIndex = 1;
            this.comboBox_Media.SelectedIndexChanged += new System.EventHandler(this.comboBox_Media_SelectedIndexChanged);
            // 
            // comboBox_PlotStyle
            // 
            this.comboBox_PlotStyle.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_PlotStyle.FormattingEnabled = true;
            this.comboBox_PlotStyle.Location = new System.Drawing.Point(135, 109);
            this.comboBox_PlotStyle.Name = "comboBox_PlotStyle";
            this.comboBox_PlotStyle.Size = new System.Drawing.Size(260, 20);
            this.comboBox_PlotStyle.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(23, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 12);
            this.label1.TabIndex = 3;
            this.label1.Text = "Printer";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 65);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(35, 12);
            this.label2.TabIndex = 4;
            this.label2.Text = "Paper";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 109);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(65, 12);
            this.label3.TabIndex = 5;
            this.label3.Text = "Plot style";
            // 
            // checkBox_LandScape
            // 
            this.checkBox_LandScape.AutoSize = true;
            this.checkBox_LandScape.Location = new System.Drawing.Point(29, 161);
            this.checkBox_LandScape.Name = "checkBox_LandScape";
            this.checkBox_LandScape.Size = new System.Drawing.Size(78, 16);
            this.checkBox_LandScape.TabIndex = 7;
            this.checkBox_LandScape.Text = "Landscape";
            this.checkBox_LandScape.UseVisualStyleBackColor = true;
            this.checkBox_LandScape.CheckedChanged += new System.EventHandler(this.checkBox_LandScape_CheckedChanged);
            // 
            // checkBox_BackGround
            // 
            this.checkBox_BackGround.AutoSize = true;
            this.checkBox_BackGround.Location = new System.Drawing.Point(155, 161);
            this.checkBox_BackGround.Name = "checkBox_BackGround";
            this.checkBox_BackGround.Size = new System.Drawing.Size(84, 16);
            this.checkBox_BackGround.TabIndex = 8;
            this.checkBox_BackGround.Text = "Background";
            this.checkBox_BackGround.UseVisualStyleBackColor = true;
            this.checkBox_BackGround.CheckedChanged += new System.EventHandler(this.checkBox_BackGround_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox_Scale);
            this.groupBox1.Controls.Add(this.checkBox_Fit);
            this.groupBox1.Location = new System.Drawing.Point(22, 203);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(116, 75);
            this.groupBox1.TabIndex = 9;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Scale";
            // 
            // textBox_Scale
            // 
            this.textBox_Scale.Location = new System.Drawing.Point(6, 42);
            this.textBox_Scale.Name = "textBox_Scale";
            this.textBox_Scale.Size = new System.Drawing.Size(100, 21);
            this.textBox_Scale.TabIndex = 10;
            this.textBox_Scale.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.textBox_Scale_Keypress);
            // 
            // checkBox_Fit
            // 
            this.checkBox_Fit.AutoSize = true;
            this.checkBox_Fit.Location = new System.Drawing.Point(6, 20);
            this.checkBox_Fit.Name = "checkBox_Fit";
            this.checkBox_Fit.Size = new System.Drawing.Size(42, 16);
            this.checkBox_Fit.TabIndex = 10;
            this.checkBox_Fit.Text = "Fit";
            this.checkBox_Fit.UseVisualStyleBackColor = true;
            this.checkBox_Fit.CheckedChanged += new System.EventHandler(this.checkBox_Fit_CheckedChanged);
            // 
            // textBox_FileName
            // 
            this.textBox_FileName.Location = new System.Drawing.Point(153, 245);
            this.textBox_FileName.Name = "textBox_FileName";
            this.textBox_FileName.Size = new System.Drawing.Size(242, 21);
            this.textBox_FileName.TabIndex = 11;
            // 
            // checkBox_PlotToFile
            // 
            this.checkBox_PlotToFile.AutoSize = true;
            this.checkBox_PlotToFile.Location = new System.Drawing.Point(154, 220);
            this.checkBox_PlotToFile.Name = "checkBox_PlotToFile";
            this.checkBox_PlotToFile.Size = new System.Drawing.Size(96, 16);
            this.checkBox_PlotToFile.TabIndex = 11;
            this.checkBox_PlotToFile.Text = "Plot to file";
            this.checkBox_PlotToFile.UseVisualStyleBackColor = true;
            this.checkBox_PlotToFile.CheckedChanged += new System.EventHandler(this.checkBox_PlotToFile_CheckedChanged);
            // 
            // button_Preview
            // 
            this.button_Preview.Location = new System.Drawing.Point(24, 296);
            this.button_Preview.Name = "button_Preview";
            this.button_Preview.Size = new System.Drawing.Size(75, 23);
            this.button_Preview.TabIndex = 12;
            this.button_Preview.Text = "Preview";
            this.button_Preview.UseVisualStyleBackColor = true;
            this.button_Preview.Click += new System.EventHandler(this.button_Preview_Click);
            // 
            // button_Plot
            // 
            this.button_Plot.Location = new System.Drawing.Point(153, 295);
            this.button_Plot.Name = "button_Plot";
            this.button_Plot.Size = new System.Drawing.Size(75, 23);
            this.button_Plot.TabIndex = 13;
            this.button_Plot.Text = "Plot";
            this.button_Plot.UseVisualStyleBackColor = true;
            this.button_Plot.Click += new System.EventHandler(this.button_Plot_Click);
            // 
            // SampleDlg
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(417, 337);
            this.Controls.Add(this.button_Plot);
            this.Controls.Add(this.button_Preview);
            this.Controls.Add(this.checkBox_PlotToFile);
            this.Controls.Add(this.textBox_FileName);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.checkBox_BackGround);
            this.Controls.Add(this.checkBox_LandScape);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox_PlotStyle);
            this.Controls.Add(this.comboBox_Media);
            this.Controls.Add(this.comboBox_Device);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SampleDlg";
            this.Text = "PlotNetSample";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBox_Device;
        private System.Windows.Forms.ComboBox comboBox_Media;
        private System.Windows.Forms.ComboBox comboBox_PlotStyle;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox checkBox_LandScape;
        private System.Windows.Forms.CheckBox checkBox_BackGround;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBox_Scale;
        private System.Windows.Forms.CheckBox checkBox_Fit;
        private System.Windows.Forms.TextBox textBox_FileName;
        private System.Windows.Forms.CheckBox checkBox_PlotToFile;
        private System.Windows.Forms.Button button_Preview;
        private System.Windows.Forms.Button button_Plot;
    }
}