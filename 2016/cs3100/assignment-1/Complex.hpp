/******************
    ComplexClass
*******************/

class ComplexClass
{

private:

public:
    float imag;
    float real;

    ComplexClass()
        : real(0),
        imag(0)
    {

    }

    ComplexClass(float real, float imag)
        : real(real),
        imag(imag)
    {

    }

    void print()
    {
        std::cout << real << "+" << imag << "i\n";
    }

    friend ComplexClass operator+(ComplexClass c1, ComplexClass c2){
        return ComplexClass(c1.real + c2.real, c1.imag + c2.imag);
    }

    friend ComplexClass operator*(ComplexClass c1, ComplexClass c2){
        return ComplexClass(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
    }

    float getReal(int j, ComplexClass c1, ComplexClass c2, int COLS){
        return c1.real + j * ((c2.real - c1.real) / COLS);
    }

    float getImag(int i, ComplexClass c1, ComplexClass c2, int ROWS){
        return c1.imag + i * ((c2.imag - c1.imag) / ROWS);
    }

    ComplexClass getComplex(int i, int j, ComplexClass c1, ComplexClass c2, int ROWS, int COLS){
        return ComplexClass(getReal(j, c1, c2, COLS), getImag(i, c1, c2, ROWS));
    }

};
