namespace LinkTest
{
    partial class Form1
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
            this.CDrive = new System.Windows.Forms.LinkLabel();
            this.Google = new System.Windows.Forms.LinkLabel();
            this.Notepad = new System.Windows.Forms.LinkLabel();
            this.SuspendLayout();
            // 
            // CDrive
            // 
            this.CDrive.AutoSize = true;
            this.CDrive.Location = new System.Drawing.Point(22, 28);
            this.CDrive.Name = "CDrive";
            this.CDrive.Size = new System.Drawing.Size(45, 13);
            this.CDrive.TabIndex = 0;
            this.CDrive.TabStop = true;
            this.CDrive.Text = "C: Drive";
            this.CDrive.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.CDrive_LinkClicked);
            // 
            // Google
            // 
            this.Google.AutoSize = true;
            this.Google.Location = new System.Drawing.Point(25, 84);
            this.Google.Name = "Google";
            this.Google.Size = new System.Drawing.Size(64, 13);
            this.Google.TabIndex = 1;
            this.Google.TabStop = true;
            this.Google.Text = "Google.com";
            this.Google.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.Google_LinkClicked);
            // 
            // Notepad
            // 
            this.Notepad.AutoSize = true;
            this.Notepad.Location = new System.Drawing.Point(28, 158);
            this.Notepad.Name = "Notepad";
            this.Notepad.Size = new System.Drawing.Size(48, 13);
            this.Notepad.TabIndex = 2;
            this.Notepad.TabStop = true;
            this.Notepad.Text = "Notepad";
            this.Notepad.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.Notepad_LinkClicked);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.Notepad);
            this.Controls.Add(this.Google);
            this.Controls.Add(this.CDrive);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.LinkLabel CDrive;
        private System.Windows.Forms.LinkLabel Google;
        private System.Windows.Forms.LinkLabel Notepad;
    }
}

