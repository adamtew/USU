#include <iostream>
#include <fstream>

using namespace std;

const int ROWS=512;
const int COLS=512;
const int INTENSITY=255;
const int MAXITERS=256;
/* Made changed here -------
const double c1real = -1.5;
const double c1imag = 1.0;
const double c2real = 0.5;
const double c2imag = -1.0;
*/

struct Complex {
    float real;
    float imag;
};

struct point{
    float x;
    float y;
};

struct color{
    int r;
    int g;
    int b;
};

void PrintComplex(Complex cplx){
    cout << cplx.real << "+" << cplx.imag << "i";
    return;
}

Complex AddComplex(Complex c1, Complex c2){
    Complex c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag+c2.imag;
    return c3;
}

Complex operator+(Complex c1, Complex c2){
    return AddComplex(c1,c2);
}

Complex MultiplyComplex(Complex c1, Complex c2){
    Complex c3;
    c3.real=c1.real*c2.real-c1.imag*c2.imag;
    c3.imag=c1.real*c2.imag+c1.imag*c2.real;
    return c3;
}

Complex operator*(Complex c1, Complex c2){
    return MultiplyComplex(c1,c2);
}


float getReal(int j, Complex c1, Complex c2){
    float real;
    float increment;
    increment=(c2.real-c1.real)/COLS;
    real=c1.real+j*increment;
    return real;
}

float getImag(int i, Complex c1, Complex c2){
    float imag;
    float increment;
    increment=(c2.imag-c1.imag)/ROWS;
    imag=c1.imag+i*increment;
    return imag;
}

Complex getComplex(int i, int j, Complex c1, Complex c2){
    Complex c;
    c.real=getReal(j,c1,c2);
    c.imag=getImag(i,c1,c2);
    return c;
}

float getx(int j, point p1, point p2){
    float x;
    float increment;
    increment=(p2.x-p1.x)/COLS;
    x=p1.x+j*increment;
    return x;
}

float gety(int i, point p1, point p2){
    float y;
    float increment;
    increment=(p2.y-p1.y)/ROWS;
    y=p1.y+i*increment;
    return y;
}

point getPoint(int i, int j, point p1, point p2){
    point p;
    p.x=getx(j,p1,p2);
    p.y=gety(i,p1,p2);
    return p;
}

color getColor(int i){
    color c;
    //i%=256;
    //i%=10
    i%=256;
    i%=2;
    c.r = i * 0;
    c.g = i * 100;
    c.b = i * 400;
    /*
    c.r=0;
    c.g=i*10;
    c.b=0;
    */
    return c;
}

int insideUnitCircle(point p){
    int i;
    if(p.x*p.x+p.y*p.y<=1)i=0;
    else i=255;
    return i;
}

int distFromOrigSq(point p){
    int d;
    d=p.x*p.x+p.y*p.y;
    return d;
}

int getMandelbrotIters(Complex c){
    int i=0;
    Complex z;
    z=c;
    while((z.real*z.real+z.imag*z.imag)<=4 && i<MAXITERS){
        z=z*z+c;
        i++;
    }
    return i;
}

void printColor(color pc, ofstream &fout){
    fout << pc.r << " ";
    fout << pc.g << " ";
    fout << pc.b << " ";
}


int main(){
    ofstream fout;
    ifstream fin("mandelinput.txt");
    Complex c1,c2;
    double c1i, c1r, c2i, c2r;

    fin >> c1.real;
    fin >> c1.imag;
    fin >> c2.real;
    c2.imag = c1.imag + (c1.real - c2.real);

    color pc;
    Complex c;
    int index;

    //print out top matter for ppm
    fout.open("mandeloutput.ppm"); 
    fout << "P3 ";
    fout << COLS << " ";
    fout << ROWS << " ";
    fout << INTENSITY << " ";
    fout << "\n";

    // for each pixel in image
    for(int i=0;i<ROWS;++i){
        for(int j=0;j<COLS;++j){
            //find the point for this pixel
            c=getComplex(i,j,c1,c2);

            //get index for that complex
            index = getMandelbrotIters(c);

            //use index value to determine a color
            pc=getColor(index);           

            //print out the pixel with that color
            printColor(pc,fout);
        }
    }


    return 0;
}