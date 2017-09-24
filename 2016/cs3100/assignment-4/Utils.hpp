#include <numeric>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <chrono>

template<typename F>
auto timeF(F f)
{
    auto start = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    return duration;
}

template<typename F>
auto getAvgStd(F times)
{
    // http://stackoverflow.com/questions/7616511/calculate-mean-and-standard-deviation-from-a-vector-of-samples-in-c-using-boos
    double sum = std::accumulate(times.begin(), times.end(), 0.0);
    double mean = sum / times.size();
    std::vector<double> diff(times.size());
    std::transform(times.begin(), times.end(), diff.begin(), [mean](double x) { return x - mean; });
    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    double stdev = sqrt(sq_sum / times.size());
    return std::make_tuple(mean, stdev);
}
