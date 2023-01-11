#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* HEAD = NULL;
int size = 0;

// int numOfNodes() {
//   struct node* link = HEAD;
//   int len = 0;

//   while (link != NULL) {
//     link = link->next;
//     len++;
//   }
//   return len;
// }

void insertBeginning(int data) { insertPos(1, data); }

void insertEnd(int data) { insertPos(size, data); }

void insertPos(int pos, int data) {
  //   int size = numOfNodes();
  if (pos < 1 || pos > size + 1) {
    printf("INVALID POSITION\n");
    return;
  }

  struct node* link = HEAD;
  struct node* toAdd = malloc(sizeof(struct node));
  toAdd->data = data;
  toAdd->next = NULL;

  if (pos == 1) {
    toAdd->next = HEAD;
    HEAD = toAdd;
    size++;
    return;
  }

  int current_pos = 1;
  while (1) {
    if (current_pos == pos - 1) {
      toAdd->next = link->next;
      link->next = toAdd;
      size++;
      return;
    }
    link = link->next;
    current_pos++;
  }
}

void printList() {
  struct node* ptr = HEAD;
  printf("\nLINKED LIST: \n");

  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }

  if (size == 0) printf("LINKED LIST IS EMPTY.\n");
  printf("\n");
}

int find(int data) {
  // int size = numOfNodes();
  if (size == 0) {
    printf("LINKED LIST IS EMPTY.\n");
    return -1;
  }

  int position = 1;
  int found = 0;
  struct node* link = HEAD;
  while (link != NULL) {
    if (link->data == data) {
      found = 1;
      return position;
    }
    link = link->next;
    position++;
  }
  return (found) ? position : -1;
}

void delete(int data) {
  // int size = numOfNodes();
  if (size == 0) {
    printf("LINKED LIST IS EMPTY.\n");
    return;
  }
  int pos = find(data);

  if (pos == 1) {
    HEAD = HEAD->next;
    return;
  }

  if (pos != -1) {
    struct node* link = HEAD;
    for (int i = 1; i <= pos; i++) {
      if (i == pos - 1) {
        link->next = link->next->next;
        return;
      }
      link = link->next;
    }
  }
  printf("SINCE DATA DOES NOT EXIST, NOTHING WAS REMOVED.\n");
  return;
}

void reverse() {
  struct node* previous = NULL;
  struct node* next = NULL;
  struct node* current = HEAD;

  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  HEAD = previous;
}

void printReverse() {
  struct node* last = HEAD;
  struct node* prev = HEAD;
  if (size == 0) return;
  while (last->next != NULL) {
    last = last->next;
  }
  printf("%d -> ", last->data);
  while (last != HEAD) {
    prev = HEAD;
    while (prev->next != last) {
      prev = prev->next;
    }
    last = prev;
    printf("%d -> ", last->data);
  }
  // printf("%d", HEAD->data);
}

int main() {
  printList();
  insertPos(1, 10);
  insertPos(2, 20);
  insertPos(2, 15);
  insertPos(3, 100);
  insertPos(5, 200);
  printList();
  printReverse();
}