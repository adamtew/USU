namespace _2412_Base_Form
{
    partial class baseForm
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
            this.labelBugs = new System.Windows.Forms.Label();
            this.buttonLearn = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // labelBugs
            // 
            this.labelBugs.AutoSize = true;
            this.labelBugs.BackColor = System.Drawing.Color.Maroon;
            this.labelBugs.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelBugs.Location = new System.Drawing.Point(28, 33);
            this.labelBugs.Name = "labelBugs";
            this.labelBugs.Size = new System.Drawing.Size(230, 31);
            this.labelBugs.TabIndex = 0;
            this.labelBugs.Text = "Bugs, Bugs, Bugs";
            // 
            // buttonLearn
            // 
            this.buttonLearn.Location = new System.Drawing.Point(31, 87);
            this.buttonLearn.Name = "buttonLearn";
            this.buttonLearn.Size = new System.Drawing.Size(256, 78);
            this.buttonLearn.TabIndex = 1;
            this.buttonLearn.Text = "Learn More";
            this.buttonLearn.UseVisualStyleBackColor = true;
            this.buttonLearn.Click += new System.EventHandler(this.buttonLearn_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(31, 199);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(256, 20);
            this.textBox1.TabIndex = 2;
            // 
            // baseForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(496, 481);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.buttonLearn);
            this.Controls.Add(this.labelBugs);
            this.Name = "baseForm";
            this.Text = "Visual Inheritance Test";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelBugs;
        private System.Windows.Forms.Button buttonLearn;
        private System.Windows.Forms.TextBox textBox1;
    }
}

