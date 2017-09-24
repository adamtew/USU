#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "Thread_Pool.hpp"
#include "Complex.hpp"
#include "Color.hpp"
#include "Utils.hpp"
#include "Mandelbrot.hpp"
#include <mutex>
#include <thread>

std::mutex mtx, mtx0, mtx1;
std::vector<std::thread> threads;
std::vector<int> times;
// const int INTENSITY = 256;
const int INTENSITY = 255;
const int MAXITERS = 256;
const int ROWS = 512;
const int COLS = 512;
const int ITERATIONS = 10;
const int THREAD_POOL = 20;
std::vector<std::vector<ColorClass>> myColors(ROWS, std::vector<ColorClass>(COLS));


void makeBrotPieces(MandelParts parts)
{
    ComplexClass myC1(-1.5, 1), myC2(.5, -1);
    ComplexClass c;
    int index;
    for(int i = parts.rowsStart; i < parts.rowsEnd; ++i){
        for(int j = parts.colsStart; j < parts.colsEnd; ++j){
            c = c.getComplex(i, j, myC1, myC2, ROWS, COLS);
            index = getMandelbrotIters(c, MAXITERS);
            ColorClass pc(index);   
            myColors[i][j] = pc;
        }
    }
}

auto random_intensity()
{
    return rand() % INTENSITY + 1;
}

auto random_iters()
{
    return rand() % MAXITERS + 1;
}

void brot_threads(std::vector<MandelParts>& parts_vector);
void brot_prints(int);
auto print_stuff()
{
    std::cout << "hi\n";
}

int main(){    

    int jobs = 1;
    Thread_Pool thread_pool(5, jobs);

    for (int i = 0;i < jobs; i++)
      thread_pool.post(print_stuff);

    thread_pool.stop();

    std::vector<MandelParts> parts_vector;

    ComplexClass myC1(-1.5, 1), myC2(.5, -1);
    ComplexClass c;
    MandelParts parts(0, ROWS, 0, COLS, random_intensity(), random_iters());
    int index;
    for(int i = parts.rowsStart; i < parts.rowsEnd; ++i){
        for(int j = parts.colsStart; j < parts.colsEnd; ++j){
            c = c.getComplex(i, j, myC1, myC2, ROWS, COLS);
            index = getMandelbrotIters(c, MAXITERS);
            ColorClass pc(index);   
            myColors[i][j] = pc;
        }
    }

    for (int i = 0; i < ITERATIONS; i++) {
        // times.push_back(stoi(timeF(parts_vector)));
        // std::cout << "This function took: " << times[i] << " milliseconds\n";
        brot_prints(i);
    }

    // std::tuple<int, int> averageDev = getAvgStd(times);
    // std::cout << "Your average was " << std::get<0>(averageDev) << " milliseconds\n";
    // std::cout << "With a standard deviation of " << std::get<1>(averageDev) << " milliseconds\n";

}



void brot_threads(std::vector<MandelParts>& parts_vector)
{
    threads.erase(threads.begin(), threads.end());
    for (int i = 0; i < THREAD_POOL; i++)
        threads.push_back(std::thread([&, i](){
            makeBrotPieces(parts_vector[i]);
        }));
    
    for (auto& th : threads)
        th.join();

    threads.erase(threads.begin(), threads.end());
}

void brot_prints(int brot_id)
{
    std::ofstream fout("brots/mandeloutput" + std::to_string(brot_id) + ".ppm");
    fout << "P3 " << ROWS << " " << COLS << " " << INTENSITY << " " << "\n";
    for (auto &color_vector : myColors) // access by reference to avoid copying
      for (auto &color : color_vector) // access by reference to avoid copying
        fout << color.r << " " << color.g << " " << color.b << " ";

    fout.close();
}