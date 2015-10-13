// Fig 19.6: LINQToFileDirectoryForm.cs
// Using LINQ to search directories and determine file types.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.IO;

namespace LINQToFileDirectory
{
   public partial class LINQToFileDirectoryForm : Form
   {
      string currentDirectory; // directory to search

      // TODO: instantiate a dictionary of (string, int) key-value pairs
      // to store extensions found, and number of each extension found
      Dictionary<string, int> found = new Dictionary<string,int>();



      // parameterless constructor
      public LINQToFileDirectoryForm()
      {
         InitializeComponent();
      } 

      // handles the Search Directory Button's Click event
      private void searchButton_Click( object sender, EventArgs e )
      {
         // check if user specified path exists
         if ( pathTextBox.Text != string.Empty && !Directory.Exists( pathTextBox.Text ) )
         {
            // show error if user does not specify valid directory
            MessageBox.Show( "Invalid Directory", "Error",
               MessageBoxButtons.OK, MessageBoxIcon.Error );
         } 
         else
         {
            // use current directory if no directory is specified
             if (pathTextBox.Text == string.Empty)
               currentDirectory = Directory.GetCurrentDirectory();
            else
               currentDirectory = pathTextBox.Text;

            directoryTextBox.Text = currentDirectory; // show directory

            // clear TextBoxes
            pathTextBox.Clear();
            resultsTextBox.Clear();

            SearchDirectory( currentDirectory ); // search the directory

            // allow user to delete .bak files
            CleanDirectory( currentDirectory );

            // TODO: summarize and display the results
            // iterate over all keys in the dictionay
            // display the number of files with current extension
            // use indexer [key] to get the count of the current extension
            //Dictionary.keys <--- return collection of keys
             foreach(var key in found.Keys)
             {
                 
                 //resultsTextBox.Text += "Key: {0}, Count: {1}\n", key, found[key];
                 //resultsTextBox.Text += "Found " + key + found[key] + " files\n";
                 int value = found[key];
                 resultsTextBox.Text += string.Format("* Found {0} {1} files\r\n", value, key);
             
             }

             //resultsTextBox.Text = "Found?";

            found.Clear(); // clear results for new search
         } 
      } 

      // search directory using LINQ
      private void SearchDirectory( string folder )
      {
         // files contained in the directory
         string[] files = Directory.GetFiles( folder );

         // subdirectories in the directory
         string[] directories = Directory.GetDirectories( folder );

         // TODO: find all file extensions in this directory
         //var extensions = folder.Split('.')[1];
         var extensions =
             (from file in files
             select Path.GetExtension(file)).Distinct();

          //Distinct() removes duplicates


         // count the number of files using each extension
         foreach ( var extension in extensions )
         {

            // TODO: count the number of files with the extension
             var extensionCount =
                 (from file in files
                 select Path.GetExtension(extension)).Count();



            // TODO: if the Dictionary already contains a key for the extension (use ContainKeys method)
            // if yes, update the count (use indexers [])
            // else add new key-value pair (extension, count) using Add method

             //found.Add(extension, extensionCount);

             if (found.ContainsKey(extension))
                 found[extension]++;
             else
                 found.Add(extension, extensionCount);
           


         } 

         // recursive call to search subdirectories
         foreach ( var subdirectory in directories )
            SearchDirectory( subdirectory );
      } 

      // allow user to delete backup files (.bak)
      private void CleanDirectory( string folder )
      {
         // files contained in the directory
         string[] files = Directory.GetFiles( folder );

         // subdirectories in the directory
         string[] directories = Directory.GetDirectories( folder );

         // TODO: select all the backup files in this directory
         var backupFiles =
             from file in files
             where Path.GetExtension(file) == ".bak"
                select file;




         // iterate over all backup files (.bak)
         foreach ( var backup in backupFiles )
         {
            DialogResult result = MessageBox.Show( "Found backup file " +
               Path.GetFileName( backup ) + ". Delete?", "Delete Backup",
               MessageBoxButtons.YesNo, MessageBoxIcon.Question );

            // delete file if user clicked 'yes'
            if ( result == DialogResult.Yes )
            {
               File.Delete( backup ); // delete backup file
               // TODO: decrement count of backup files in Dictionary

               found[".bak"]--;



               // if there are no .bak files, delete key from Dictionary
               if ( found[ ".bak" ] == 0 )
                  found.Remove( ".bak" );
            } 
         } 

         // recursive call to clean subdirectories
         foreach ( var subdirectory in directories )
            CleanDirectory( subdirectory );
      } 
   } 
} 