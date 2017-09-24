// This pipes the output of cmd1 into cmd2.
void pipe_cmd(char** cmd1, char** cmd2) {
  int fds[2]; // file descriptors
  pipe(fds);
  pid_t pid;

  // child process #1
  if (fork() == 0) {
    // Reassign stdin to fds[0] end of pipe.
    dup2(fds[0], 0);

    // Not going to write in this child process, so we can close this end
    // of the pipe.
    close(fds[1]);

    // Execute the second command.
    execvp(cmd2[0], cmd2);
    perror("execvp failed");

  // child process #2
  } else if ((pid = fork()) == 0) {
    // Reassign stdout to fds[1] end of pipe.
    dup2(fds[1], 1);

    // Not going to read in this child process, so we can close this end
    // of the pipe.
    close(fds[0]);

    // Execute the first command.
    execvp(cmd1[0], cmd1);
    perror("execvp failed");

  // parent process
  } else
    waitpid(pid, NULL, 0);
}

void redirect_cmd(char** cmd, char** file) {
  int fds[2]; // file descriptors
  int count;  // used for reading from stdout
  int fd;     // single file descriptor
  char c;     // used for writing and reading a character at a time
  pid_t pid;  // will hold process ID; used with fork()

  pipe(fds);

  // child process #1
  if (fork() == 0) {
    // Thanks to http://linux.die.net/man/2/open for showing which headers
    // need to be included to use this function and its flags.
    fd = open(file[0], O_RDWR | O_CREAT, 0666);

    // open() returns a -1 if an error occurred
    if (fd < 0) {
      printf("Error: %s\n", strerror(errno));
      return;
    }

    dup2(fds[0], 0);

    // Don't need stdout end of pipe.
    close(fds[1]);

    // Read from stdout...
    while ((count = read(0, &c, 1)) > 0)
      write(fd, &c, 1); // Write to file.

    // Okay, so this is a bit contrived, but when I didn't have any kind of exec
    // function call here, I got my SarahShell prompt repeated over and over
    // again on the Multilab machines, I think because of this crazy child
    // process or something.  When I put this execlp here with the useless call
    // to echo, however, that looping stops and you can actually enter things
    // at the prompt again, hurray!
    execlp("echo", "echo", NULL);

  // child process #2
  } else if ((pid = fork()) == 0) {
    dup2(fds[1], 1);

    // Don't need stdin end of pipe.
    close(fds[0]);

    // Output contents of the given file to stdout.
    execvp(cmd[0], cmd);
    perror("execvp failed");

  // parent process
  } else {
    waitpid(pid, NULL, 0);
    close(fds[0]);
    close(fds[1]);
  }
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