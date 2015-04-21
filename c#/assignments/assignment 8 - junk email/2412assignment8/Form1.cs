using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections;
using System.Text.RegularExpressions;

namespace _2412assignment8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void submitButton_Click(object sender, EventArgs e)
        {
            double score = 0;
            List<string> words = new List<string>();
            List<string> foundWords = new List<string>();
            
            foreach (string item in listBox1.Items)
                words.Add(item);
            foreach (string item in listBox2.Items)
                words.Add(item);
            foreach (string item in listBox3.Items)
                words.Add(item);
            foreach (string item in listBox4.Items)
                words.Add(item);
            //foreach (string item in emailText.Text)
            //    words.Add(item);
            string[] email = emailText.Text.Split(' ');
            string[] emailCopy = email;
            //email.Split(" ");

            //Regex regex = ".";
            listBox5.Items.Clear();
            double emailWords = 0;
            foreach(string item in email)
            {
                emailWords++;
                foreach(string word in words)
                if(emailText.Text.Contains(word))
                {
                    foundWords.Add(word);
                    Regex rex = new Regex(word);
                    emailText.Text = ReplaceLastOccurrence(emailText.Text, word, "");
                    //emailText.Text = rex.Replace(emailText.Text, word, "");
                    //emailText.Text = emailText.Text.Replace(word, " ", 1);
                    score += 1;
                    break;
                }
                            
            }

            emailText.Text = "";
            foreach (string mail in email)
            {
                emailText.Text += mail;
                emailText.Text += " ";
            }
            emailText.Text = emailText.Text.Remove(emailText.Text.Length - 1);

            if (emailWords == 0) emailWords = 1;
            
            scoreText.Text = score.ToString();
            double rate = (score / emailWords) * 100;
            rateText.Text = ((score / emailWords) * 100).ToString("N2");
            //rateText.Text = emailWords.ToString("N2");

            //listBox5.Items.Clear();
            foreach (string word in foundWords)
            {
                listBox5.Items.Add(word);
            }
                  
                
        }

        private void addButton_Click(object sender, EventArgs e)
        {
            listBox4.Items.Add(addText.Text);
            addText.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            emailText.Text = "";
            scoreText.Text = "";
            rateText.Text = "";
            emailText.BackColor = Color.White;
            emailText.ForeColor = Color.Black;

            listBox5.Items.Clear();
        }

        public static string ReplaceLastOccurrence(string Source, string Find, string Replace)
        {
            int Place = Source.LastIndexOf(Find);
            string result = Source.Remove(Place, Find.Length).Insert(Place, Replace);
            return result;
        }
    }
}
