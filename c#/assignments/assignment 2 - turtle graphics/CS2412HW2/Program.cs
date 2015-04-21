using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CS2412HW2
{
    class Program
    {
        public const int SIZE = 20;
        static void Main(string[] args)
        {
            Turtle turtle = new Turtle();
            turtle.startOptions();

        }
    }

    class Turtle
    {
        private const int SIZE = 20;
        private int[,] m_aFloor = new int[SIZE, SIZE];

        private int m_x;
        public int X
        {
            get { return m_x; }
            set { m_x = value; }
        }

        private int m_y;
        public int Y
        {
            get { return m_y; }
            set { m_y = value; }
        }

        private bool m_penDown;
        public bool PenDown
        {
            get { return m_penDown; }
            set { m_penDown = value; }
        }

        private char m_dir;
        public char Dir
        {
            get { return m_dir; }
            set { m_dir = value; }
        }

        private bool m_decisions;
        public bool Decisions
        {
            get { return m_decisions; }
            set { m_decisions = value; }
        }

        public Turtle()
        {
            m_penDown = false;
            m_dir = 'S';
            m_x = 0;
            m_y = 0;
            initializeFloor();
        }

        public void initializeFloor()
        {
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                {
                    m_aFloor[i, j] = 0;
                }
        }

        public void printFloor()
        {
            Console.WriteLine(" _________________________________________");
            for (int i = 0; i < SIZE; i++)
            {
                Console.Write("|");
                for (int j = 0; j < SIZE; j++)
                {
                    if (m_aFloor[i, j] == 0)
                    {
                        Console.Write(" ");
                    }
                    else
                    {
                        Console.Write("*");
                    }
                    Console.Write(" ");

                }
                Console.Write(" |\n");
            }
            Console.WriteLine("|_________________________________________|");
        }

        public void penUp()
        {
            m_penDown = false;
        }

        public void penDown()
        {
            m_penDown = true;
            m_aFloor[m_x, m_y] = 1;
        }

        public void turnLeft()
        {
            switch(m_dir)
            {
                case 'N': m_dir = 'W'; break;
                case 'W': m_dir = 'S'; break;
                case 'S': m_dir = 'E'; break;
                case 'E': m_dir = 'N'; break;
                default: break;
            }
        }

        public void turnRight()
        {
            switch (m_dir)
            {
                case 'N': m_dir = 'E'; break;
                case 'E': m_dir = 'S'; break;
                case 'S': m_dir = 'W'; break;
                case 'W': m_dir = 'N'; break;
                default: break;
            }
        }

        public void forward(int k)
        {
            for (int i = 0; i < k; i++)
            {
                
                switch (m_dir)
                {
                    case 'N': 
                        if (checkWall(m_y - 1))
                        {
                            m_y--;
                        }
                        else
                        {
                            Console.WriteLine("That's a wall");
                        }
                         break;
                    case 'E':  
                         if (checkWall(m_x + 1))
                         {
                             m_x++;
                         }
                         else
                         {
                             Console.WriteLine("That's a wall");
                         }
                         break;
                    case 'S': 
                        if (checkWall(m_y + 1))
                        {
                            m_y++;
                        }
                        else
                        {
                            Console.WriteLine("That's a wall");
                        }
                        break;
                    case 'W':
                        if (checkWall(m_x - 1))
                        {
                            m_x--;
                        }
                        else
                        {
                            Console.WriteLine("That's a wall");
                        }
                        break;
                    default: break;
                }
                if (m_penDown)
                    m_aFloor[m_y, m_x] = 1;
            }
            //forward(k - 1);
        }

        public bool checkWall(int check)
        {
            if(check >= SIZE || check < 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        public void showOptions()
        {
            string pen;
            if (m_penDown) pen = "Down";
            else pen = " Up ";
            Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine("----------------------------");
            Console.WriteLine("|   {0}    Options    {1}   |", pen, m_dir);
            Console.WriteLine("----------------------------");
            Console.WriteLine("(1)    Pen up               ");
            Console.WriteLine("(2)    Pen down             ");
            Console.WriteLine("(3)    Turn right           ");
            Console.WriteLine("(4)    Turn left            ");
            Console.WriteLine("(5)    Move forward         ");
            Console.WriteLine("(6)    Show floor           ");
            Console.WriteLine();
            Console.WriteLine("(9)    Quit                 ");
            Console.WriteLine("----------------------------");
            Console.WriteLine();
            Console.Write("Option: ");

            decision();
        }

        public void decision()
        {
            int choice = Convert.ToInt32(Console.ReadLine());
            switch(choice)
            {
                case 1: penUp(); break;
                case 2: penDown(); break;
                case 3: turnRight(); break;
                case 4: turnLeft(); break;
                case 5: Console.Write("Distance: ");
                    forward(Convert.ToInt32(Console.ReadLine())); break;
                case 6: printFloor(); break;
                case 9: m_decisions = false; break;
                default: break;
            }
        }

        public void startOptions()
        {
            m_decisions = true;
            while(m_decisions)
            {
                showOptions();
            }

        }

    }
}
