namespace RadioButtonTest
{
   partial class RadioButtonTestForm
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
            this.displayLabel = new System.Windows.Forms.Label();
            this.okCancelRadioButton = new System.Windows.Forms.RadioButton();
            this.buttonTypeGroupBox = new System.Windows.Forms.GroupBox();
            this.okRadioButton = new System.Windows.Forms.RadioButton();
            this.displayButton = new System.Windows.Forms.Button();
            this.iconTypeGroupBox = new System.Windows.Forms.GroupBox();
            this.exclamationRadioButton = new System.Windows.Forms.RadioButton();
            this.errorRadioButton = new System.Windows.Forms.RadioButton();
            this.buttonTypeGroupBox.SuspendLayout();
            this.iconTypeGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // displayLabel
            // 
            this.displayLabel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.displayLabel.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.displayLabel.Location = new System.Drawing.Point(12, 173);
            this.displayLabel.Name = "displayLabel";
            this.displayLabel.Size = new System.Drawing.Size(236, 23);
            this.displayLabel.TabIndex = 30;
            this.displayLabel.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // okCancelRadioButton
            // 
            this.okCancelRadioButton.AutoSize = true;
            this.okCancelRadioButton.Location = new System.Drawing.Point(6, 47);
            this.okCancelRadioButton.Name = "okCancelRadioButton";
            this.okCancelRadioButton.Size = new System.Drawing.Size(77, 19);
            this.okCancelRadioButton.TabIndex = 2;
            this.okCancelRadioButton.Text = "OKCancel";
            this.okCancelRadioButton.CheckedChanged += new System.EventHandler(this.buttonType_CheckedChanged);
            // 
            // buttonTypeGroupBox
            // 
            this.buttonTypeGroupBox.Controls.Add(this.okCancelRadioButton);
            this.buttonTypeGroupBox.Controls.Add(this.okRadioButton);
            this.buttonTypeGroupBox.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.buttonTypeGroupBox.Location = new System.Drawing.Point(12, 12);
            this.buttonTypeGroupBox.Name = "buttonTypeGroupBox";
            this.buttonTypeGroupBox.Size = new System.Drawing.Size(130, 104);
            this.buttonTypeGroupBox.TabIndex = 27;
            this.buttonTypeGroupBox.TabStop = false;
            this.buttonTypeGroupBox.Text = "Button Type";
            // 
            // okRadioButton
            // 
            this.okRadioButton.AutoSize = true;
            this.okRadioButton.Location = new System.Drawing.Point(6, 22);
            this.okRadioButton.Name = "okRadioButton";
            this.okRadioButton.Size = new System.Drawing.Size(41, 19);
            this.okRadioButton.TabIndex = 1;
            this.okRadioButton.Text = "OK";
            this.okRadioButton.CheckedChanged += new System.EventHandler(this.buttonType_CheckedChanged);
            // 
            // displayButton
            // 
            this.displayButton.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.displayButton.Location = new System.Drawing.Point(12, 121);
            this.displayButton.Name = "displayButton";
            this.displayButton.Size = new System.Drawing.Size(236, 44);
            this.displayButton.TabIndex = 29;
            this.displayButton.Text = "Display";
            // 
            // iconTypeGroupBox
            // 
            this.iconTypeGroupBox.Controls.Add(this.exclamationRadioButton);
            this.iconTypeGroupBox.Controls.Add(this.errorRadioButton);
            this.iconTypeGroupBox.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.iconTypeGroupBox.Location = new System.Drawing.Point(148, 12);
            this.iconTypeGroupBox.Name = "iconTypeGroupBox";
            this.iconTypeGroupBox.Size = new System.Drawing.Size(100, 104);
            this.iconTypeGroupBox.TabIndex = 28;
            this.iconTypeGroupBox.TabStop = false;
            this.iconTypeGroupBox.Text = "Icon";
            // 
            // exclamationRadioButton
            // 
            this.exclamationRadioButton.AutoSize = true;
            this.exclamationRadioButton.Location = new System.Drawing.Point(6, 47);
            this.exclamationRadioButton.Name = "exclamationRadioButton";
            this.exclamationRadioButton.Size = new System.Drawing.Size(89, 19);
            this.exclamationRadioButton.TabIndex = 9;
            this.exclamationRadioButton.Text = "Exclamation";
            // 
            // errorRadioButton
            // 
            this.errorRadioButton.AutoSize = true;
            this.errorRadioButton.Location = new System.Drawing.Point(6, 22);
            this.errorRadioButton.Name = "errorRadioButton";
            this.errorRadioButton.Size = new System.Drawing.Size(50, 19);
            this.errorRadioButton.TabIndex = 8;
            this.errorRadioButton.Text = "Error";
            // 
            // RadioButtonTestForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(260, 206);
            this.Controls.Add(this.displayLabel);
            this.Controls.Add(this.buttonTypeGroupBox);
            this.Controls.Add(this.displayButton);
            this.Controls.Add(this.iconTypeGroupBox);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Name = "RadioButtonTestForm";
            this.Text = "Demonstrating RadioButtons";
            this.buttonTypeGroupBox.ResumeLayout(false);
            this.buttonTypeGroupBox.PerformLayout();
            this.iconTypeGroupBox.ResumeLayout(false);
            this.iconTypeGroupBox.PerformLayout();
            this.ResumeLayout(false);

      }

      #endregion

      internal System.Windows.Forms.Label displayLabel;
      internal System.Windows.Forms.RadioButton okCancelRadioButton;
      internal System.Windows.Forms.GroupBox buttonTypeGroupBox;
      internal System.Windows.Forms.RadioButton okRadioButton;
      internal System.Windows.Forms.Button displayButton;
      internal System.Windows.Forms.GroupBox iconTypeGroupBox;
      internal System.Windows.Forms.RadioButton exclamationRadioButton;
      internal System.Windows.Forms.RadioButton errorRadioButton;
   }
}

