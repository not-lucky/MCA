#include <stdio.h>
#include <unistd.h>

int main() {
  int child_pid;
  child_pid = fork();

  if (child_pid > 0) {
    printf("I am the parent process (PID: %d)\n", getpid());
    printf("My child's PID is: %d\n", child_pid);
  } else if (child_pid == 0) {
    printf("I am the child process (PID: %d)\n", getpid());
  }
}