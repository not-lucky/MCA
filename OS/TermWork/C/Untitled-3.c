#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void initializePageTable(int* pageTable, int numPages);
int findVictimPage(int* pageTable, int numPages, int currentTime);

int main() {
  // Initialize the page table and the number of pages
  int pageTable[10];
  int numPages = 0;

  // Read in the number of pages from the user
  printf("Enter the number of pages: ");
  scanf("%d", &numPages);

  // Initialize the page table
  initializePageTable(pageTable, numPages);

  // Initialize the current time to 0
  int currentTime = 0;

  // Initialize the page faults counter to 0
  int numPageFaults = 0;

  // Loop until the user enters a negative number
  int pageRequest = 0;
  while (pageRequest >= 0) {
    // Read in a page request from the user
    printf("Enter page request (-1 to quit): ");
    scanf("%d", &pageRequest);

    // Check if the page request is valid
    if (pageRequest < 0 || pageRequest >= numPages) {
      continue;
    }

    // Check if the page is already in the page table
    int foundPage = 0;
    for (int i = 0; i < numPages; i++) {
      if (pageTable[i] == pageRequest) {
        foundPage = 1;
        printf("Victim: %d \n", pageRequest);
        break;
      }
    }

    // If the page is not in the page table, we need to page fault
    if (!foundPage) {
      // Find the victim page to replace
      int victimPage = findVictimPage(pageTable, numPages, currentTime);

      // Replace the victim page with the requested page
      pageTable[victimPage] = pageRequest;

      // Increment the page faults counter
      numPageFaults++;
    }

    // Update the current time
    currentTime++;
  }

  // Print the number of page faults
  printf("Number of page faults: %d\n", numPageFaults);

  return 0;
}

// Function to initialize the page table
void initializePageTable(int* pageTable, int numPages) {
  for (int i = 0; i < numPages; i++) {
    pageTable[i] = -1;
  }
}

// Function to find the victim page to replace
int findVictimPage(int* pageTable, int numPages, int currentTime) {
  int victimPage = 0;

  // Find the first page that was added to the page table
  int minTime = currentTime;
  for (int i = 0; i < numPages; i++) {
    if (pageTable[i] != -1 && pageTable[i] < minTime) {
      victimPage = i;
      minTime = pageTable[i];
    }
  }
  return victimPage;
}
