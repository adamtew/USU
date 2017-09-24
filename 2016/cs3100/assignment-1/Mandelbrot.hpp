#include <fstream>

class MandelParts
{
public:
    int rows, cols, intensity, maxiters;
    MandelParts() {};
    MandelParts(int r, int c, int i, int m)
        : rows(r), cols(c), intensity(i), maxiters(m) {}
};

void printBrot(std::vector<ColorClass>& colors, std::ofstream& fout)
{
  for (auto &color : colors) // access by reference to avoid copying
    printColor(color, fout);
}

int getMandelbrotIters(ComplexClass c, int maxiters)
{
    int i = 0;
    ComplexClass z = c;
    while ((z.real * z.real + z.imag * z.imag) <= 4 && ++i < maxiters)
        z = z * z + c;
    return i;
}

