namespace Trees
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("Child1");
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("Child2");
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("Root1", new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2});
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("Child3");
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("Child4");
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("Root2", new System.Windows.Forms.TreeNode[] {
            treeNode4,
            treeNode5});
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            System.Windows.Forms.ListViewGroup listViewGroup1 = new System.Windows.Forms.ListViewGroup("ListViewGroup", System.Windows.Forms.HorizontalAlignment.Left);
            System.Windows.Forms.ListViewItem listViewItem1 = new System.Windows.Forms.ListViewItem("myText", 0);
            System.Windows.Forms.ListViewItem listViewItem2 = new System.Windows.Forms.ListViewItem("");
            System.Windows.Forms.ListViewItem listViewItem3 = new System.Windows.Forms.ListViewItem("");
            this.DirTree = new System.Windows.Forms.TreeView();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.myPath = new System.Windows.Forms.TextBox();
            this.GetPath = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.listView1 = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.imageList2 = new System.Windows.Forms.ImageList(this.components);
            this.SuspendLayout();
            // 
            // DirTree
            // 
            this.DirTree.Location = new System.Drawing.Point(12, 54);
            this.DirTree.Name = "DirTree";
            treeNode1.Name = "Child1";
            treeNode1.Text = "Child1";
            treeNode2.Name = "Child2";
            treeNode2.Text = "Child2";
            treeNode3.Name = "Root1";
            treeNode3.Text = "Root1";
            treeNode4.Name = "Child3";
            treeNode4.Text = "Child3";
            treeNode5.Name = "Child4";
            treeNode5.Text = "Child4";
            treeNode6.Name = "Root2";
            treeNode6.Text = "Root2";
            this.DirTree.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode3,
            treeNode6});
            this.DirTree.Size = new System.Drawing.Size(270, 212);
            this.DirTree.TabIndex = 0;
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "1557_10151315152718221_535864501_n.jpg");
            // 
            // myPath
            // 
            this.myPath.Location = new System.Drawing.Point(12, 28);
            this.myPath.Name = "myPath";
            this.myPath.Size = new System.Drawing.Size(189, 20);
            this.myPath.TabIndex = 1;
            // 
            // GetPath
            // 
            this.GetPath.Location = new System.Drawing.Point(207, 25);
            this.GetPath.Name = "GetPath";
            this.GetPath.Size = new System.Drawing.Size(75, 23);
            this.GetPath.TabIndex = 2;
            this.GetPath.Text = "Get Path";
            this.GetPath.UseVisualStyleBackColor = true;
            this.GetPath.Click += new System.EventHandler(this.GetPath_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(181, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Enter a path to get the subdirectories";
            // 
            // listView1
            // 
            this.listView1.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1});
            listViewGroup1.Header = "ListViewGroup";
            listViewGroup1.Name = "listViewGroup1";
            this.listView1.Groups.AddRange(new System.Windows.Forms.ListViewGroup[] {
            listViewGroup1});
            this.listView1.Items.AddRange(new System.Windows.Forms.ListViewItem[] {
            listViewItem1,
            listViewItem2,
            listViewItem3});
            this.listView1.LargeImageList = this.imageList1;
            this.listView1.Location = new System.Drawing.Point(299, 54);
            this.listView1.Name = "listView1";
            this.listView1.Size = new System.Drawing.Size(271, 212);
            this.listView1.SmallImageList = this.imageList1;
            this.listView1.TabIndex = 4;
            this.listView1.UseCompatibleStateImageBehavior = false;
            // 
            // imageList2
            // 
            this.imageList2.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList2.ImageStream")));
            this.imageList2.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList2.Images.SetKeyName(0, "1557_10151315152718221_535864501_n.jpg");
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(591, 261);
            this.Controls.Add(this.listView1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.GetPath);
            this.Controls.Add(this.myPath);
            this.Controls.Add(this.DirTree);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TreeView DirTree;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.TextBox myPath;
        private System.Windows.Forms.Button GetPath;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ListView listView1;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ImageList imageList2;
    }
}

