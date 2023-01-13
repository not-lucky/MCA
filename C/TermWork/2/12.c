#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* HEAD = NULL;
int size = 0;

void insertBeginning() {
  int data;
  printf("Enter the data to enter: ");
  scanf("%d", &data);
  insertPos(1, data);
}

void insertEnd() {
  int data;
  printf("Enter the data to enter: ");
  scanf("%d", &data);
  insertPos(size + 1, data);
}

void insertPos(int pos, int data) {
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
    printf("%d => ", ptr->data);
    ptr = ptr->next;
  }

  if (size == 0) printf("LINKED LIST IS EMPTY.\n");
  printf("\n");
}

void find() {
  int data;
  printf("Enter the data to search: ");
  scanf("%d", &data);
  if (size == 0) {
    printf("LINKED LIST IS EMPTY.\n");
    return -1;
  }

  int position = 1;
  int found = 0;
  struct node* link = HEAD;
  while (link != NULL) {
    if (link->data == data) {
      printf("Data was found aat position: %d", position);
      return;
    }
    link = link->next;
    position++;
  }
  printf("Data is not in the linked list.");
}

void delete() {
  int data;
  printf("Enter the data to delete: ");
  scanf("%d", &data);
  if (size == 0) {
    printf("LINKED LIST IS EMPTY.\n");
    return;
  }

  if (HEAD->data == data) {
    HEAD = HEAD->next;
    return;
  }

  struct node* temp = HEAD;
  while (temp != NULL) {
    if (temp->next->data == data) {
      temp->next = temp->next->next;
      printf("Data deleted.\n");
      return;
    }
    temp = temp->next;
  }
  printf("SINCE DATA DOES NOT EXIST, NOTHING WAS REMOVED.\n");
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
  printf("NULL");
}

void sort() {
  struct node* i;
  struct node* j;
  struct node* min;
  for (i = HEAD; i->next != NULL; i = i->next) {
    min = i;
    for (j = i->next; j != NULL; j = j->next) {
      if (j->data < min->data) min = j;
    }
    int temp = i->data;
    i->data = min->data;
    min->data = temp;
  }
}

int main() {
  int ch;
  while (1) {
    printf(
        "\n1. Insert at Beginning\n2.Insert at End\n3.Insert at specific "
        "postion\n4. Display\n5. Delete\n6. Reverse "
        "Display\n7. Reverse the linked list\n8. Search\n9. Sort\n"
        "10. Exit\nEnter your "
        "choice: ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        insertBeginning();
        break;
      case 2:
        insertEnd();
        break;
      case 3:
        int data;
        printf("Enter the data to enter: ");
        scanf("%d", &data);
        int pos;
        printf("Enter the pos to input data at: ");
        scanf("%d", &pos);
        insertPos(pos, data);
        break;
      case 4:
        printList();
        break;
      case 5:
        delete ();
        break;
      case 6:
        printReverse();
        break;
      case 7:
        reverse();
        break;
      case 8:
        find();
        break;
      case 9:
        sort();
        break;
      case 10:
        return 0;
      default:
        printf("\nInvalid choice");
    }
  }
}