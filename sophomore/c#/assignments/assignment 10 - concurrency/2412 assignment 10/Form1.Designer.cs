namespace _2412_assignment_10
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
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("Test Item");
            this.searchTextBox = new System.Windows.Forms.TextBox();
            this.seachButton = new System.Windows.Forms.Button();
            this.folderList = new System.Windows.Forms.ListView();
            this.folderTree = new System.Windows.Forms.TreeView();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // searchTextBox
            // 
            this.searchTextBox.Location = new System.Drawing.Point(12, 12);
            this.searchTextBox.Name = "searchTextBox";
            this.searchTextBox.Size = new System.Drawing.Size(287, 20);
            this.searchTextBox.TabIndex = 0;
            this.searchTextBox.Text = "c:\\";
            // 
            // seachButton
            // 
            this.seachButton.Location = new System.Drawing.Point(317, 9);
            this.seachButton.Name = "seachButton";
            this.seachButton.Size = new System.Drawing.Size(75, 23);
            this.seachButton.TabIndex = 1;
            this.seachButton.Text = "Search";
            this.seachButton.UseVisualStyleBackColor = true;
            this.seachButton.Click += new System.EventHandler(this.seachButton_Click);
            // 
            // folderList
            // 
            this.folderList.CheckBoxes = true;
            this.folderList.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            listViewItem2.StateImageIndex = 0;
            this.folderList.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem2});
            this.folderList.Location = new System.Drawing.Point(237, 38);
            this.folderList.Margin = new System.Windows.Forms.Padding(10);
            this.folderList.Name = "folderList";
            this.folderList.Size = new System.Drawing.Size(341, 467);
            this.folderList.TabIndex = 2;
            this.folderList.TileSize = new System.Drawing.Size(20, 20);
            this.folderList.UseCompatibleStateImageBehavior = false;
            this.folderList.View = System.Windows.Forms.View.List;
            // 
            // folderTree
            // 
            this.folderTree.Location = new System.Drawing.Point(12, 38);
            this.folderTree.Name = "folderTree";
            this.folderTree.Size = new System.Drawing.Size(219, 467);
            this.folderTree.TabIndex = 3;
            this.folderTree.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.folderTree_AfterSelect);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(398, 9);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Delete";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(590, 514);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.folderTree);
            this.Controls.Add(this.folderList);
            this.Controls.Add(this.seachButton);
            this.Controls.Add(this.searchTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox searchTextBox;
        private System.Windows.Forms.Button seachButton;
        private System.Windows.Forms.ListView folderList;
        private System.Windows.Forms.TreeView folderTree;
        private System.Windows.Forms.Button button1;
    }
}

