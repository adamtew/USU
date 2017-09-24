// // Some algorithms from sundberg
// // cach algorithm base class
// #include <vector>
// #include <iostream>
// #include <random>
// #include <memory>
// #include <algorithm>

// class Cache
// {
//   public:
//     Cache(int size) :size(size){};
//     virtual int run(std::vector<int>) = 0;
//     virtual std:string name() = 0;
//     protected:
//       int size;


// };

// class Fifo : public Cache
// {
// public:
//   Fifo(int size) : Cache(size){};

//   int run(std::vector<int> data) override 
//   {
//     std::vector<int> c(size);
//     std::generate(c.begin(), c.end(), []{return -1});
//     int miss = 0;
//     int cur = 0;
//     for (auto request : data)
//     {
//       if (std::find(c.begin(), c.end(), request) == c.end())
//       {
//         ++miss;
//         c[cur] = request;
//         cur = (cur + 1) % size;
//       }
//     }



//     return miss;
//   } // this is meant to override a virtual function in my base class
//   std::string name() override { return std::string("FIFO");}
// };

// class SecondChance : public Cache
// {
// public:
//   SecondChance(int size) : Cache(size){};

//   int run(std::vector<int>) override { return -1;} // this is meant to override a virtual function in my base class
//   std::string name() override { return std::string("SECONDCHANCE");}
// };

// class LRU : public Cache
// {
// public:
//   LRU(int size) : Cache(size){};

//   int run(std::vector<int>) override { return -1;} // this is meant to override a virtual function in my base class
//   std::string name() override { return std::string("LRU");}
// };

// class MRU : public Cache
// {
// public:
//   MRU(int size) : Cache(size){};

//   int run(std::vector<int>) override 
//   {
//     std::vector<int> c(size);
//     std::generate(c.begin(), c.end(), []{return -1});
//     int miss = 0;
//     int last = 0;
//     std::vector<int>::iterator last = 0;
//     for (auto request : data)
//     {
//       auto cur = std::find(c.begin(), c.end(), request) == c.end();
//       if (cur == c.end());
//       {
//         ++miss;
//         auto pos = std::funct(c.begin(), c.end(), -1);
//         if (pos != c.end())
//         {
//           *pos = request;
//         }
//         else
//         {
//           *last = request;
//         }
//         else // means we did find it but what we found is the most recently used thing so we need to find where it is and keep track of that index
//         {
//           last = cur;
//         }
//       }
//     }
//     return miss;
//   } // this is meant to override a virtual function in my base class
//   std::string name() override { return std::string("MRU");}
// };

// class Opt : public Cache
// {
// public:
//   Opt(int size) : Cache(size){};

//   int run(std::vector<int>) override { return -1;} // this is meant to override a virtual function in my base class
//   std::string name() override { return std::string("Opt");}
// };


// // something to generate a list of things

// std::vector<int> make_list(int n)
// {
//   std::vector<int> result(n);
//   static std::random_device rd();
//   static std::my19937 mt(rd());
//   std::uniform_int_distribution<> dist(0, 1024);
//   std::generate(result.begin(), result.end(), [&](){return dist(mt);});
//   return result;
// }


// int main()
// {
  
//   for(int size = 16; size < 4096; size *= 2)
//   {
//     std::vector<std::unique_ptr<Cache>> algs;
//     algs.push_back(std::make_unique<Fifo>(size));
//     algs.push_back(std::make_unique<SecondChance>(size));
//     algs.push_back(std::make_unique<LRU>(size));
//     algs.push_back(std::make_unique<MRU>(size));
//     algs.push_back(std::make_unique<Opt>(size));

//     auto data = make_list(8192); // same data for all files...
//     std::cout << "size " << size << ":\t";
//     for (auto && a : algs) // double reference is an "r value reference" says I want to use the thing don't make a copy
//     {
//       std::cout << a->name() << " " << a->run(data) << "\t";
//       // a->run(data);
//     }
//     std::cout << "\n":
//     // for each algorithm
//   } 
// }