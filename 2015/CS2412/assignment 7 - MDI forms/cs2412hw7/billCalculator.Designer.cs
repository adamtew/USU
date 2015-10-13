namespace cs2412hw7
{
    partial class billCalculator
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
            this.bevCombo = new System.Windows.Forms.ComboBox();
            this.appCombo = new System.Windows.Forms.ComboBox();
            this.maiCombo = new System.Windows.Forms.ComboBox();
            this.desCombo = new System.Windows.Forms.ComboBox();
            this.bevNum = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.subText = new System.Windows.Forms.TextBox();
            this.taxText = new System.Windows.Forms.TextBox();
            this.totalText = new System.Windows.Forms.TextBox();
            this.desNum = new System.Windows.Forms.NumericUpDown();
            this.maiNum = new System.Windows.Forms.NumericUpDown();
            this.appNum = new System.Windows.Forms.NumericUpDown();
            this.bevPrice = new System.Windows.Forms.TextBox();
            this.appPrice = new System.Windows.Forms.TextBox();
            this.maiPrice = new System.Windows.Forms.TextBox();
            this.desPrice = new System.Windows.Forms.TextBox();
            this.addBevButton = new System.Windows.Forms.Button();
            this.addDesButton = new System.Windows.Forms.Button();
            this.addMaiButton = new System.Windows.Forms.Button();
            this.addAppButton = new System.Windows.Forms.Button();
            this.clearButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.bevNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.desNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.maiNum)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.appNum)).BeginInit();
            this.SuspendLayout();
            // 
            // bevCombo
            // 
            this.bevCombo.FormattingEnabled = true;
            this.bevCombo.Items.AddRange(new object[] {
            "Soda",
            "Tea",
            "Coffee",
            "Mineral Water",
            "Juice",
            "Milk"});
            this.bevCombo.Location = new System.Drawing.Point(53, 36);
            this.bevCombo.Name = "bevCombo";
            this.bevCombo.Size = new System.Drawing.Size(121, 21);
            this.bevCombo.TabIndex = 0;
            this.bevCombo.Text = "Beverages";
            this.bevCombo.SelectedIndexChanged += new System.EventHandler(this.bevCombo_SelectedIndexChanged);
            // 
            // appCombo
            // 
            this.appCombo.FormattingEnabled = true;
            this.appCombo.Items.AddRange(new object[] {
            "Nachos",
            "Mushroom Caps",
            "Shrimp Cocktail",
            "Chips and Salsa"});
            this.appCombo.Location = new System.Drawing.Point(53, 64);
            this.appCombo.Name = "appCombo";
            this.appCombo.Size = new System.Drawing.Size(121, 21);
            this.appCombo.TabIndex = 1;
            this.appCombo.Text = "Appetizers";
            this.appCombo.SelectedIndexChanged += new System.EventHandler(this.appCombo_SelectedIndexChanged);
            // 
            // maiCombo
            // 
            this.maiCombo.FormattingEnabled = true;
            this.maiCombo.Items.AddRange(new object[] {
            "Seafood Alfredo",
            "Chicken Alfredo",
            "Chicken Picatta",
            "Turkey Club",
            "Lobster Pie",
            "Prime Rib",
            "Shrimp Scampi",
            "Turkey Dinner",
            "Stuffed Chicken"});
            this.maiCombo.Location = new System.Drawing.Point(53, 91);
            this.maiCombo.Name = "maiCombo";
            this.maiCombo.Size = new System.Drawing.Size(121, 21);
            this.maiCombo.TabIndex = 2;
            this.maiCombo.Text = "Main Course";
            this.maiCombo.SelectedIndexChanged += new System.EventHandler(this.maiCombo_SelectedIndexChanged);
            // 
            // desCombo
            // 
            this.desCombo.FormattingEnabled = true;
            this.desCombo.Items.AddRange(new object[] {
            "Applie Pie",
            "Sundae",
            "Carrot Cake",
            "Mud Pie",
            "Applie Crisp"});
            this.desCombo.Location = new System.Drawing.Point(53, 118);
            this.desCombo.Name = "desCombo";
            this.desCombo.Size = new System.Drawing.Size(121, 21);
            this.desCombo.TabIndex = 3;
            this.desCombo.Text = "Desserts";
            this.desCombo.SelectedIndexChanged += new System.EventHandler(this.desCombo_SelectedIndexChanged);
            // 
            // bevNum
            // 
            this.bevNum.Location = new System.Drawing.Point(231, 36);
            this.bevNum.Name = "bevNum";
            this.bevNum.Size = new System.Drawing.Size(50, 20);
            this.bevNum.TabIndex = 4;
            this.bevNum.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(62, 159);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Subtotal:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(62, 214);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(31, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Total";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(62, 183);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(28, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Tax:";
            // 
            // subText
            // 
            this.subText.Location = new System.Drawing.Point(130, 156);
            this.subText.Name = "subText";
            this.subText.Size = new System.Drawing.Size(64, 20);
            this.subText.TabIndex = 9;
            this.subText.Text = "0.00";
            this.subText.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // taxText
            // 
            this.taxText.Location = new System.Drawing.Point(130, 183);
            this.taxText.Name = "taxText";
            this.taxText.Size = new System.Drawing.Size(64, 20);
            this.taxText.TabIndex = 10;
            this.taxText.Text = "0.00";
            this.taxText.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // totalText
            // 
            this.totalText.Location = new System.Drawing.Point(130, 211);
            this.totalText.Name = "totalText";
            this.totalText.Size = new System.Drawing.Size(64, 20);
            this.totalText.TabIndex = 11;
            this.totalText.Text = "0.00";
            this.totalText.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // desNum
            // 
            this.desNum.Location = new System.Drawing.Point(231, 119);
            this.desNum.Name = "desNum";
            this.desNum.Size = new System.Drawing.Size(50, 20);
            this.desNum.TabIndex = 12;
            this.desNum.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // maiNum
            // 
            this.maiNum.Location = new System.Drawing.Point(231, 92);
            this.maiNum.Name = "maiNum";
            this.maiNum.Size = new System.Drawing.Size(50, 20);
            this.maiNum.TabIndex = 13;
            this.maiNum.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // appNum
            // 
            this.appNum.Location = new System.Drawing.Point(231, 62);
            this.appNum.Name = "appNum";
            this.appNum.Size = new System.Drawing.Size(50, 20);
            this.appNum.TabIndex = 14;
            this.appNum.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // bevPrice
            // 
            this.bevPrice.Location = new System.Drawing.Point(181, 36);
            this.bevPrice.Name = "bevPrice";
            this.bevPrice.Size = new System.Drawing.Size(46, 20);
            this.bevPrice.TabIndex = 15;
            this.bevPrice.Text = "0.00";
            this.bevPrice.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // appPrice
            // 
            this.appPrice.Location = new System.Drawing.Point(180, 65);
            this.appPrice.Name = "appPrice";
            this.appPrice.Size = new System.Drawing.Size(46, 20);
            this.appPrice.TabIndex = 16;
            this.appPrice.Text = "0.00";
            this.appPrice.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // maiPrice
            // 
            this.maiPrice.Location = new System.Drawing.Point(181, 92);
            this.maiPrice.Name = "maiPrice";
            this.maiPrice.Size = new System.Drawing.Size(46, 20);
            this.maiPrice.TabIndex = 17;
            this.maiPrice.Text = "0.00";
            this.maiPrice.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // desPrice
            // 
            this.desPrice.Location = new System.Drawing.Point(181, 119);
            this.desPrice.Name = "desPrice";
            this.desPrice.Size = new System.Drawing.Size(46, 20);
            this.desPrice.TabIndex = 18;
            this.desPrice.Text = "0.00";
            this.desPrice.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // addBevButton
            // 
            this.addBevButton.Location = new System.Drawing.Point(299, 33);
            this.addBevButton.Name = "addBevButton";
            this.addBevButton.Size = new System.Drawing.Size(75, 23);
            this.addBevButton.TabIndex = 19;
            this.addBevButton.Text = "Add";
            this.addBevButton.UseVisualStyleBackColor = true;
            this.addBevButton.Click += new System.EventHandler(this.addBevButton_Click);
            // 
            // addDesButton
            // 
            this.addDesButton.Location = new System.Drawing.Point(299, 116);
            this.addDesButton.Name = "addDesButton";
            this.addDesButton.Size = new System.Drawing.Size(75, 23);
            this.addDesButton.TabIndex = 20;
            this.addDesButton.Text = "Add";
            this.addDesButton.UseVisualStyleBackColor = true;
            this.addDesButton.Click += new System.EventHandler(this.addDesButton_Click);
            // 
            // addMaiButton
            // 
            this.addMaiButton.Location = new System.Drawing.Point(299, 88);
            this.addMaiButton.Name = "addMaiButton";
            this.addMaiButton.Size = new System.Drawing.Size(75, 23);
            this.addMaiButton.TabIndex = 21;
            this.addMaiButton.Text = "Add";
            this.addMaiButton.UseVisualStyleBackColor = true;
            this.addMaiButton.Click += new System.EventHandler(this.addMaiButton_Click);
            // 
            // addAppButton
            // 
            this.addAppButton.Location = new System.Drawing.Point(299, 59);
            this.addAppButton.Name = "addAppButton";
            this.addAppButton.Size = new System.Drawing.Size(75, 23);
            this.addAppButton.TabIndex = 22;
            this.addAppButton.Text = "Add";
            this.addAppButton.UseVisualStyleBackColor = true;
            this.addAppButton.Click += new System.EventHandler(this.addAppButton_Click);
            // 
            // clearButton
            // 
            this.clearButton.Location = new System.Drawing.Point(281, 179);
            this.clearButton.Name = "clearButton";
            this.clearButton.Size = new System.Drawing.Size(93, 48);
            this.clearButton.TabIndex = 23;
            this.clearButton.Text = "Clear";
            this.clearButton.UseVisualStyleBackColor = true;
            this.clearButton.Click += new System.EventHandler(this.clearButton_Click);
            // 
            // billCalculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(433, 274);
            this.Controls.Add(this.clearButton);
            this.Controls.Add(this.addAppButton);
            this.Controls.Add(this.addMaiButton);
            this.Controls.Add(this.addDesButton);
            this.Controls.Add(this.addBevButton);
            this.Controls.Add(this.desPrice);
            this.Controls.Add(this.maiPrice);
            this.Controls.Add(this.appPrice);
            this.Controls.Add(this.bevPrice);
            this.Controls.Add(this.appNum);
            this.Controls.Add(this.maiNum);
            this.Controls.Add(this.desNum);
            this.Controls.Add(this.totalText);
            this.Controls.Add(this.taxText);
            this.Controls.Add(this.subText);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.bevNum);
            this.Controls.Add(this.desCombo);
            this.Controls.Add(this.maiCombo);
            this.Controls.Add(this.appCombo);
            this.Controls.Add(this.bevCombo);
            this.Name = "billCalculator";
            this.Text = "billCalculator";
            ((System.ComponentModel.ISupportInitialize)(this.bevNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.desNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.maiNum)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.appNum)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox bevCombo;
        private System.Windows.Forms.ComboBox appCombo;
        private System.Windows.Forms.ComboBox maiCombo;
        private System.Windows.Forms.ComboBox desCombo;
        private System.Windows.Forms.NumericUpDown bevNum;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox subText;
        private System.Windows.Forms.TextBox taxText;
        private System.Windows.Forms.TextBox totalText;
        private System.Windows.Forms.NumericUpDown desNum;
        private System.Windows.Forms.NumericUpDown maiNum;
        private System.Windows.Forms.NumericUpDown appNum;
        private System.Windows.Forms.TextBox bevPrice;
        private System.Windows.Forms.TextBox appPrice;
        private System.Windows.Forms.TextBox maiPrice;
        private System.Windows.Forms.TextBox desPrice;
        private System.Windows.Forms.Button addBevButton;
        private System.Windows.Forms.Button addDesButton;
        private System.Windows.Forms.Button addMaiButton;
        private System.Windows.Forms.Button addAppButton;
        private System.Windows.Forms.Button clearButton;
    }
}