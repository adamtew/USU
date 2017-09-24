/*
    Copyright 2008 Sarah Vessels

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

// Will be used to create an array to hold individual arguments passed by
// the user on the command line.
const int MAX_ARGS = 256;

enum PipeRedirect {PIPE, REDIRECT, NEITHER};

// Splits a user's command into two commands, or a command and a file name.
PipeRedirect parse_command(int, char**, char**, char**);

// Pipes the first command's output into the second.
void pipe_cmd(char**, char**);

// Reads input from the user into the given array and returns the number of
// arguments taken in.
int read_args(char**);

// Redirects the output from the given command into the given file.
void redirect_cmd(char**, char**);

// Given the number of arguments and an array of arguments, this will execute
// those arguments.  The first argument in the array should be a command.
void run_cmd(int, char**);

// Given a string of user input, this will determine if the user wants to
// quit the shell.
bool want_to_quit(string);