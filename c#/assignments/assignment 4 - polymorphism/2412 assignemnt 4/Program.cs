using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2412_assignemnt_4
{
    class Program
    {
        static void Main(string[] args)
        {
            //Circle a = new Circle();
            //Square b = new Square();
            //b.setArea(5);
            //Console.WriteLine("Area square: {0}", b.getArea());
            //Circle c = new Circle(5);
            //Console.WriteLine("Area circle: {0}", c.getArea());
            //Triangle d = new Triangle(5, 6);
            //Console.WriteLine("Area triangle: {0}", d.getArea());

            //Cube e = new Cube(5);
            //Console.WriteLine("Area Cube: {0}", e.getArea());
            //Console.WriteLine("Volume Cube: {0}", e.getVolume());

            //Sphere f = new Sphere(5);
            //Console.WriteLine("Area Sphere: {0}", f.getArea());
            //Console.WriteLine("Volume Sphere: {0}", f.getVolume());

            //Tetrahedron g = new Tetrahedron(5);
            //Console.WriteLine("Area Tetrahedron: {0}", g.getArea());
            //Console.WriteLine("Volume Tetrahedron: {0}", g.getVolume());

            const int SIZE = 6;
            Shape[] a = new Shape[SIZE];
            a[0] = new Square(5);
            a[1] = new Circle(5);
            a[2] = new Triangle(5, 5);
            a[3] = new Cube(5);
            a[4] = new Sphere(5);
            a[5] = new Tetrahedron(5);
           
            for(int i = 0; i < SIZE; i++)
            {
                Console.WriteLine("Volume {0}: {0}", a[i].GetType(), a[i]);
            }
        }
    }
}
