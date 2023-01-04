#include <stdio.h>
#include <stdlib.h>
int main() {
  printf(
      "Extracting system information using gcc compiler.\n\n");
  printf("Model Name\n");
  system("cat /proc/cpuinfo | grep -m 1 'model name'");
  printf("Cache Size\n");
  system("cat /proc/cpuinfo | grep -m 1 'cache size'");
  printf("Number of CPU CORES\n");
  system("cat /proc/cpuinfo | grep -m 1 'cpu cores'");
  printf("CPU Clock Speed\n");
  system("cat /proc/cpuinfo | grep -m 1 'cpu MHz'");
  printf("Total Memory\n");
  system("cat /proc/meminfo | grep -m 1 'MemTotal'");
  printf("Free memory\n");
  system("cat /proc/meminfo | grep -m 1 'MemFree'");
  printf("OS Name:\n");
  system("cat /etc/os-release | grep -m 1 'NAME'");
  printf("OS Version\n");
  system("cat /etc/os-release | grep -m 1 'VERSION'");
}
