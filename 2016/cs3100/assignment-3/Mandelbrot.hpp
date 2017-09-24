#include <fstream>

class MandelParts
{
public:
    int rowsStart, rowsEnd, colsStart, colsEnd, intensity, maxiters;
    MandelParts() {};
    MandelParts(int rStart, int rEnd, int cStart, int cEnd, int i, int m)
        : rowsStart(rStart), rowsEnd(rEnd), colsStart(cStart), colsEnd(cEnd), intensity(i), maxiters(m) {}

};

int getMandelbrotIters(ComplexClass c, int maxiters)
{
    int i = 0;
    ComplexClass z = c;
    while ((z.real * z.real + z.imag * z.imag) <= 4 && ++i < maxiters)
        z = z * z + c;
    return i;
}

