#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>

#include "Complex.hpp"
#include "Color.hpp"
#include "Utils.hpp"
#include "Mandelbrot.hpp"

std::vector<ColorClass> myColors;

void makeBrotPieces(MandelParts parts)
{
    ComplexClass myC1(-1.5, 1), myC2(.5, -1);
    ComplexClass c;
    int index;
    for(int i = 0; i < parts.rows; ++i){
        for(int j = 0; j < parts.cols; ++j){
            c = c.getComplex(i, j, myC1, myC2, parts.rows, parts.cols);
            index = getMandelbrotIters(c, parts.maxiters);
            ColorClass pc(index);
            myColors.push_back(pc);
        }
    }
}

int main(){
    std::ofstream fout;
    std::vector<int> times;
    int iterations = 10;
    MandelParts parts(512, 512, 255, 256);
    ComplexClass c1(-1.5, 1);
    ComplexClass c2(.5, -1);
    std::string s;
    std::string time;

    for(int i = 0; i < iterations; i++)
    {
        s = "brots/mandeloutput" + std::to_string(i) + ".ppm";
        time = timeF(makeBrotPieces, parts);
        times.push_back(stoi(time));
        fout.open(s);
        fout << "P3 " << parts.cols << " " << parts.rows << " " << parts.intensity << " " << "\n";
        std::cout << "This function took: " << time << " milliseconds\n";
        printBrot(myColors, fout);

        fout.close();
    }

    std::tuple<int, int> averageDev = getAvgStd(times);
    std::cout << "\nYour average was " << std::get<0>(averageDev) << " milliseconds.\n";
    std::cout << "With a standard deviation of " << std::get<1>(averageDev) << " milliseconds\n";
    return 0;
}
