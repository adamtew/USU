using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Trees
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        public void PopulateTreeView(
            string directoryValue, TreeNode parentNode)
        {
            string[] directoryArray;
            directoryArray = Directory.GetDirectories(directoryValue);
            //[System.IO.Path]::GetFileNameWithoutExtension("C:\\");
            try
            {
                if (directoryArray.Length != 0)
                {
                    foreach(string directory in directoryArray)
                    {
                        string subdirectoryName = Path.GetFileNameWithoutExtension(directoryValue);

                        TreeNode child = new TreeNode(subdirectoryName);

                        parentNode.Nodes.Add(child);

                       PopulateTreeView(subdirectoryName, parentNode);
                    }
                }
            }
            catch (UnauthorizedAccessException)
            {
                parentNode.Nodes.Add("Access denied");
            }
            //Directory.Exists(Path), GetDirectories(Path), GetCurrentDirectory(), GetFileNameWithoutExtension(Path)
        }
        private void GetPath_Click(object sender, EventArgs e)
        {
            DirTree.Nodes.Clear();
            
            if(Directory.Exists(myPath.Text))
            {
                DirTree.Nodes.Add(myPath.Text);
                PopulateTreeView(myPath.Text, DirTree.Nodes[0]);
            }
            else
            {
                MessageBox.Show(myPath.Text + " could not be found.",
                    "Directory Not Found", MessageBoxButtons.OK,
                    MessageBoxIcon.Error);
            }
        }
       
    }
}
