#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>

std::vector<std::vector<char *> > history;
std::chrono::duration<double, std::milli> ptime;

auto parse_string(std::string s)
{
  std::vector<char *> command;
  s = s + ' ';
  auto current = s.begin();
  while(current != s.end()) {
    std::string iter;
    auto next = std::find(current, s.end(), ' ');
    std::copy(current, next, iter.begin());
    char *push = strdup(iter.c_str());
    command.push_back(push);
    ++next;
    current = next;
  }
  command.push_back(nullptr);
  history.push_back(command);
}

void print_history()
{
  int i = 0;
  for (auto& story : history)
  {
    std::cout << i << ": ";
    for (auto& c : history[i++])
      if (c != nullptr)
        std::cout << c << " ";
    std::cout << "\n";
  }
}

auto get_ptime()
{
  return std::to_string(ptime.count());
}

void redo_history()
{
  int command = stoi(std::string(history.back()[0]).substr(1));
  std::cout << std::string(history[command][0]) << "\n";
  history.push_back(history[command]);
}

void fork_process()
{
  int i = 0;
  auto start = std::chrono::steady_clock::now();
  auto pid = fork();
  if(pid < 0) {
    perror("The following error has occurred");
    exit(EXIT_FAILURE);
  }
  else if(pid > 0) { // this is the parent
    waitpid(pid, &i, WNOHANG|WUNTRACED); // pass an integer by reference
    auto stop = std::chrono::steady_clock::now();
    ptime = stop - start;
   // store parsedcommand in history
  }
  else // child
  {
    char **command = &history.back()[0];
    execvp(command[0], command);
    perror("The following error has occurred");
    exit(EXIT_FAILURE);
  }
}

int get_value(std::string value)
{
  if (value == "exit") return 0;
  if (value == "history") return 1;
  if (value == "ptime") return 2;
  if (value[0] == '^') return 3;
  return 9;
}

void process_loop()
{
 std::string words;
  bool x = true;
  while (x)
  {
    std::cout << "> ";
    std::getline(std::cin, words);
    parse_string(words);
    switch (get_value(history.back()[0]))
    {
      case 0: x = false; break;
      case 1: print_history(); break;
      case 2: std::cout << "ptime: " << get_ptime() << " milliseconds\n"; break;
      case 3: redo_history(); fork_process(); break;
      default: fork_process(); break;
    }
  }
}

int main()
{
  process_loop();
  return 0;
}

// if your function causes no side effects then you don't need to keep it local
// non-determinstic
// depends on context
// always prefer non-member, non-friend functions

// word -> [a >= a]^+
// cmd -> word(w word)*
// piped -> cmd(| cmd)*
// command -> piped (< file)? (>file)?
// -> piped (> file)? (< file)?


// things you'll need
// 1. to copy the file descriptor
// 2. cin cout // make sure to do this after the fork // do dup2 once you're inside the child
// 
/* ******************* */
// DO THIS IN THE CHILD
/* ******************* */
// dup2(old, new)
// auto in = fopen("/* file we're trying to redirect */")
// dup2(in, 0) // or dup2(in, 1) if you want output
// dup2(in, STDIN); // dup2(in, STDOUT);
//
// Example
// ls > ls.txt
// fork();
// std::fopen('ls.txt');
// dup2(out, STDOUT);
// execvp('', '');
// 
// 
// 
// pipe // shared memory
// takes an array of integers of size 2 and returns nothing
// void pip(int[2]&);
// int foo[2];
// pip(foo); // creates shared memory structure that has a file descriptor for reading and one for writing
// it puts the reading one at index 0 and the writing one at index 1
// CMD I|O CMD2
// out <-1
//     0-> IN