using System;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;


namespace _2412_assignment_10
{
    public partial class Form1 : Form
    {
        string myFile;
        List<string> listItems;
        public Form1()
        {
            InitializeComponent();
            searchTextBox.Text = Directory.GetCurrentDirectory();
            searchTextBox.Text = "C:\\Users\\User\\Documents";
        }
        private async void getFiles(string dir, TreeNode parent)
        {
            //string[] files = Path.GetFileName(dir);
            string[] files = Directory.GetFiles(dir);
            folderList.Clear();
            //string[] files = Path.GetFileNameWithoutExtension(dir);
            try
            {
                if (files.Length != 0)
                    foreach (string file in files)
                    {
                        folderList.Items.Add(Path.GetFileName(file));
                    }
            }
            catch (UnauthorizedAccessException)
            {
                TreeNode child = new TreeNode("Access denied");
                AddNode(parent, child);
                parent.Nodes.Add("Access denied");
            }

        }
        private async void getFilesAndDirs(string dir, TreeNode parent)
        {
            //string[] files = Path.GetFileName(dir);
            string[] files = Directory.GetFiles(dir);
            folderList.Clear();
            //string[] files = Path.GetFileNameWithoutExtension(dir);
            try
            {
                
                if (files.Length != 0)
                    foreach (string file in files)
                    {
                        folderList.Items.Add(Path.GetFileName(file));
                    }
                    getDirs(dir, parent);
            }
            catch (UnauthorizedAccessException)
            {
                TreeNode child = new TreeNode("Access denied");
                AddNode(parent, child);
                parent.Nodes.Add("Access denied");
            }

        }

        private async void getDirs(string searched, TreeNode parent)
        {
            string[] dirs = Directory.GetDirectories(searched);
            //string[] files = Path.GetFileNameWithoutExtension(dirs[0]);
            TreeNode myNode = new TreeNode();
            string myDir = "x";
            try
            {
                if (dirs.Length != 0)
                {
                    foreach (string dir in dirs)
                    {
                        myFile = Path.GetFileNameWithoutExtension(dir);
                        myDir = dir;
                        myNode = new TreeNode(myFile);

                        parent.Nodes.Add(myNode);

                        getDirs(dir, myNode);
                    }
                }
                    
            }
            catch (UnauthorizedAccessException)
            {
                getDirs(myDir, myNode);
                TreeNode child = new TreeNode("Access denied");
                AddNode(parent, child);
                parent.Nodes.Add("Access denied");
            }
        }

        private void AddNode(TreeNode parent, TreeNode child)
        {
            if (InvokeRequired)
            {
                Invoke(new MethodInvoker(() => AddNode(parent, child)));
            }
            else
                parent.Nodes.Add(child);
        }

        private async void seachButton_Click(object sender, EventArgs e)
        {
            folderList.Items.Clear();
            folderTree.Nodes.Clear();
            
            if(Directory.Exists(searchTextBox.Text))
            {
                folderTree.Nodes.Add(searchTextBox.Text);
                getFilesAndDirs(searchTextBox.Text, folderTree.Nodes[0]);
            }
            else
                MessageBox.Show(searchTextBox.Text + " could not be found.",
                   "Directory Not Found", MessageBoxButtons.OK,
                   MessageBoxIcon.Error);
        }


        private void folderTree_AfterSelect(object sender, TreeViewEventArgs e)
        {
            try
            {
                getFiles(e.Node.FullPath, e.Node);
            }
            catch (UnauthorizedAccessException)
            {

            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Task task = Task.Run(() => removeItem());
        }

        private async void removeItem()
        {
            foreach (ListViewItem item in folderList.Items)
                if (item.Checked)
                    item.Remove();
        }

    }
}
