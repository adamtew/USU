using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _2412assignment_6
{
    public partial class Form1 : Form
    {
        Dictionary<char, string> keyboard = new Dictionary<char, string>();
        Dictionary<char, string> letterCount = new Dictionary<char, string>();
        Dictionary<string, int> worstChar = new Dictionary<string, int>();
        //char[] lvl1Text = "A typed word is counted as any five keystrokes.".ToCharArray();
        string[] allText = new string[] { 
            "A typed word is counted as any five keystrokes.",
            "Do not stop to correct your errors in these first tests but check them out.",
            "The beautiful scenic country of New Zealand is situated in the South Pacific to the east of Australia.",
            "The ferry crosses Cook Strait and cruises beautiful Queen Charlotte Sounds between Wellington, NZ's Capital City, and Picton.",
            "NZ's East Coast has many stretches of white sand and rolling surf which attract NZ and overseas surfers. They are popular NZ family holiday places.",
            "New Zealand is a land of contrasts, which attract thousands of overseas tourists every year to climb, ski or snowboard our mountains, swim, fish or cruise on our lakes and rivers.",
            "Between The Southern Alps and the West Coast is a fantastic scenic drive taking the Haast Pass road. Here is our great rain forest. Most overseas and local tours include this route in their Itinerary.",
            "New Zealand is a very sport oriented country and sometimes hosts world events. Sports include tennis, golf, yachting, canoeing, cruising, cricket, soccer, rugby, basketball, netball, swimming, surf lifesaving, athletics, and riding.",
            "Watching events where they take place is fine but many can only watch at home as the event is screened on our TVs. New Zealand is proud too of our sporting participants who have entered and gained medals in many sporting events including Olympic Games",
            "Masters' Games are very popular in New Zealand as in many other countries and NZ swimmers were really proud in the year 2002 to host the FINA World Masters Swimming Champs at Christchurch in the South Island, at which I gained 10th place medals for 100 m and 200 m backstroke.",
            "Some challenging events which draw overseas sports people include the annual Coast to Coast involving running, cycling and kayaking from the West Coast, through mountain passes to the East Coast, and the Iron Man including running, cycling, and swimming. I am proud one of my sons twice took part in the Ironman."};

        int j = 0;
        string phrase;
        char letter;
        int currentLetter = 0;
        int countCorrect;
        int countIncorrect;
        public Form1()
        {
            InitializeComponent();
            this.ActiveControl = typeText;
           
            keyboard.Add('a', "k_a");
            keyboard.Add('b', "k_b");
            keyboard.Add('c', "k_c");
            keyboard.Add('d', "k_d");
            keyboard.Add('e', "k_e");
            keyboard.Add('f', "k_f");
            keyboard.Add('g', "k_g");
            keyboard.Add('h', "k_h");
            keyboard.Add('i', "k_i");
            keyboard.Add('j', "k_j");
            keyboard.Add('k', "k_k");
            keyboard.Add('l', "k_l");
            keyboard.Add('m', "k_m");
            keyboard.Add('n', "k_n");
            keyboard.Add('o', "k_o");
            keyboard.Add('p', "k_p");
            keyboard.Add('q', "k_q");
            keyboard.Add('r', "k_r");
            keyboard.Add('s', "k_s");
            keyboard.Add('t', "k_t");
            keyboard.Add('u', "k_u");
            keyboard.Add('v', "k_v");
            keyboard.Add('w', "k_w");
            keyboard.Add('x', "k_x");
            keyboard.Add('y', "k_y");
            keyboard.Add('z', "k_z");
            keyboard.Add(' ', "k_space");
            keyboard.Add('\b', "k_back");
            keyboard.Add(',', "k_comma");
            keyboard.Add('.', "k_period");
            keyboard.Add(';', "k_semi");
            keyboard.Add('\'', "k_apos");
            keyboard.Add('0', "k_0");
            keyboard.Add('1', "k_1");
            keyboard.Add('2', "k_2");
            keyboard.Add('3', "k_3");
            keyboard.Add('4', "k_4");
            keyboard.Add('5', "k_5");
            keyboard.Add('6', "k_6");
            keyboard.Add('7', "k_7");
            keyboard.Add('8', "k_8");
            keyboard.Add('9', "k_9");

            worstChar.Add("a", 0);
            worstChar.Add("b", 0);
            worstChar.Add("c", 0);
            worstChar.Add("d", 0);
            worstChar.Add("e", 0);
            worstChar.Add("f", 0);
            worstChar.Add("g", 0);
            worstChar.Add("h", 0);
            worstChar.Add("i", 0);
            worstChar.Add("j", 0);
            worstChar.Add("k", 0);
            worstChar.Add("l", 0);
            worstChar.Add("m", 0);
            worstChar.Add("n", 0);
            worstChar.Add("o", 0);
            worstChar.Add("p", 0);
            worstChar.Add("q", 0);
            worstChar.Add("r", 0);
            worstChar.Add("s", 0);
            worstChar.Add("t", 0);
            worstChar.Add("u", 0);
            worstChar.Add("v", 0);
            worstChar.Add("w", 0);
            worstChar.Add("x", 0);
            worstChar.Add("y", 0);
            worstChar.Add("z", 0);
            worstChar.Add(" ", 0);
            worstChar.Add("\b", 0);
            worstChar.Add(",", 0);
            worstChar.Add(".", 0);
            worstChar.Add(";", 0);
            worstChar.Add("\'", 0);
            worstChar.Add("0", 0);
            worstChar.Add("1", 0);
            worstChar.Add("2", 0);
            worstChar.Add("3", 0);
            worstChar.Add("4", 0);
            worstChar.Add("5", 0);
            worstChar.Add("6", 0);
            worstChar.Add("7", 0);
            worstChar.Add("8", 0);
            worstChar.Add("9", 0);

            testText.Text = allText[j];
            CurrentChar(currentLetter);
            colorButtons();
            lvl1.BackColor = Color.Black;
            lvl1.ForeColor = Color.White;
            foreach (var key in keyboard)
            {
                this.Controls.Find(key.Value, true)[0].BackColor = Color.LightGray;
                this.Controls.Find(key.Value, true)[0].ForeColor = Color.White;
            }
        }


       

     


        private void CurrentChar(int c)
        {
            for (int i = 0; i < testText.Text.Length + 1; i++)
            {
                testText.SelectionLength = i;
                testText.SelectionColor = Color.Black;
                testText.SelectionBackColor = Color.White;
            }
            
            testText.SelectionStart = c;
            testText.SelectionLength = 1;
            testText.SelectionColor = Color.Black;
            testText.SelectionBackColor = Color.Red;
        }

        private void CurrentWorst()
        {

        }

        private void lvl1_Click(object sender, EventArgs e)
        {
            testText.Text = allText[0];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl1.BackColor = Color.Black;
            lvl1.ForeColor = Color.White;
        }

     

        private void correctText_KeyPress(object sender, KeyPressEventArgs e)
        {

        }

        private void typeText_KeyPress(object sender, KeyPressEventArgs e)
        {

            string value;
            if (keyboard.TryGetValue(e.KeyChar, out value))
                this.Controls.Find(value, true)[0].BackColor = Color.Black;
            var key = keyboard.FirstOrDefault(x => x.Value == value).Key;



            if (currentLetter >= testText.Text.Length - 1)
            {
                
                currentLetter = -1;
                j += 1;
                if (j == 11)
                {
                    var most = worstChar.Values.Max();
                    var worstestletter = worstChar.FirstOrDefault(x => x.Value == most).Key;
                    MessageBox.Show(string.Format ("Finished!\nLooks like you need to work on the \"{0}\" character.\nYou missed it {1} times.", worstestletter.ToString(), most.ToString() ), "Results", MessageBoxButtons.OK );
                    Application.Exit();
                }
                colorButtons();
                this.Controls.Find("lvl" + (j + 1).ToString(), true)[0].BackColor = Color.Black;
                this.Controls.Find("lvl" + (j + 1).ToString(), true)[0].ForeColor = Color.White;
                testText.Text = allText[j];
                typeText.Text = "";
            }
            currentLetter += 1;
            CurrentChar(currentLetter);
            int currentCheck = currentLetter - 1;
            if (currentCheck == -1) currentCheck = 0;
            if (allText[j].ToCharArray()[currentCheck].ToString().ToLower() == key.ToString())
            {
                countCorrect += 1;
            }
            else
            {

                countIncorrect += 1;

                testText.SelectionStart = currentCheck;
                testText.SelectionLength = 1;
                phrase = testText.SelectedText;
                worstChar[phrase.ToLower()] += 1;
                // worstText.Text = phrase;
            }
            correctText.Text = countCorrect.ToString();
            incorrectText.Text = countIncorrect.ToString();


            var max = worstChar.Values.Max();
            worstCount.Text = max.ToString();

            var worstletter = worstChar.FirstOrDefault(x => x.Value == max).Key;
            worstText.Text = worstletter.ToString();
            countLetters();
        }

        private void typeText_KeyUp(object sender, KeyEventArgs e)
        {
            foreach (var key in keyboard)
            {
                this.Controls.Find(key.Value, true)[0].BackColor = Color.LightGray;
                this.Controls.Find(key.Value, true)[0].ForeColor = Color.White;
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {

        }



        private void countLetters()
        {

            foreach(KeyValuePair<string, int> entry in worstChar)
            {
                //this.Controls.Find("l_" + entry.Key, true)[0].Text = entry.Value.ToString();
                try
                {
                    this.Controls.Find("l_" + entry.Key, true)[0].Text = entry.Value.ToString();
                }
                catch
                {

                }
                if(entry.Key == ";")
                    this.Controls.Find("l_semi", true)[0].Text = entry.Value.ToString();
                if(entry.Key == "\'")
                    this.Controls.Find("l_apos", true)[0].Text = entry.Value.ToString();
                if(entry.Key == ",")
                    this.Controls.Find("l_comma", true)[0].Text = entry.Value.ToString();
                if(entry.Key == ".")
                    this.Controls.Find("l_period", true)[0].Text = entry.Value.ToString();
                if (entry.Key == " ")
                    this.Controls.Find("l_space", true)[0].Text = entry.Value.ToString();
            }
        }

        private void lvl11_Click(object sender, EventArgs e)
        {
            j = 10;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl11.BackColor = Color.Black;
            lvl11.ForeColor = Color.White;
        }

        private void lvl2_Click(object sender, EventArgs e)
        {
            j = 1;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl2.BackColor = Color.Black;
            lvl2.ForeColor = Color.White;
        }

        private void lvl3_Click(object sender, EventArgs e)
        {
            j = 2;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl3.BackColor = Color.Black;
            lvl3.ForeColor = Color.White;
        }

        private void lvl4_Click(object sender, EventArgs e)
        {
            j = 3;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl4.BackColor = Color.Black;
            lvl4.ForeColor = Color.White;
        }

        private void lvl5_Click(object sender, EventArgs e)
        {
            j = 4;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl5.BackColor = Color.Black;
            lvl5.ForeColor = Color.White;
        }

        private void lvl6_Click(object sender, EventArgs e)
        {
            j = 5;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl6.BackColor = Color.Black;
            lvl6.ForeColor = Color.White;
        }

        private void lvl7_Click(object sender, EventArgs e)
        {
            j = 6;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl7.BackColor = Color.Black;
            lvl7.ForeColor = Color.White;
        }

        private void lvl8_Click(object sender, EventArgs e)
        {
            j = 7;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl8.BackColor = Color.Black;
            lvl8.ForeColor = Color.White;
        }

        private void lvl9_Click(object sender, EventArgs e)
        {
            j = 8;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl9.BackColor = Color.Black;
            lvl9.ForeColor = Color.White;
        }

        private void lvl10_Click(object sender, EventArgs e)
        {
            j = 9;
            testText.Text = allText[j];
            currentLetter = 0;
            CurrentChar(currentLetter);
            colorButtons();
            lvl10.BackColor = Color.Black;
            lvl10.ForeColor = Color.White;
        }

        private void colorButtons()
        {
            lvl1.BackColor = Color.Gainsboro;
            lvl2.BackColor = Color.Gainsboro;
            lvl3.BackColor = Color.Gainsboro;
            lvl4.BackColor = Color.Gainsboro;
            lvl5.BackColor = Color.Gainsboro;
            lvl6.BackColor = Color.Gainsboro;
            lvl7.BackColor = Color.Gainsboro;
            lvl8.BackColor = Color.Gainsboro;
            lvl9.BackColor = Color.Gainsboro;
            lvl10.BackColor = Color.Gainsboro;
            lvl11.BackColor = Color.Gainsboro;

            lvl1.ForeColor = Color.Black;
            lvl2.ForeColor = Color.Black;
            lvl3.ForeColor = Color.Black;
            lvl4.ForeColor = Color.Black;
            lvl5.ForeColor = Color.Black;
            lvl6.ForeColor = Color.Black;
            lvl7.ForeColor = Color.Black;
            lvl8.ForeColor = Color.Black;
            lvl9.ForeColor = Color.Black;
            lvl10.ForeColor = Color.Black;
            lvl11.ForeColor = Color.Black;
        }
    }
}



