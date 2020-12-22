#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  Node *next;
}*head = NULL, *tail = NULL;

Node *createNode(int value) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void pushTail(int value) {
  Node *temp = createNode(value);
  if(!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }

}

void printLinkedList() {
  Node *curr = head;
  printf("The Elements are:\n");
  while(curr) {
    printf("%d->", curr->value);
    curr = curr->next;
  }
  printf("NULL\n");
}


int main() {
  int i = 0;
  //assume LinkedList is given :
  pushTail(3);
  pushTail(4);
  pushTail(5);
  pushTail(1);
  pushTail(3);
  pushTail(8);

  Node *curr = head;
  while(curr) {
    i++;
   // printf("i berjalan = %d\n", i);
    curr = curr->next;
  }
  if(i%2 == 0) {
    i/=2;
  } else {
    i = (i+1) / 2;
  }
  //printf("i = %d\n", i);
  int j = 0;
  Node *curr2 = head;
  printLinkedList();
  while(curr2) {
    j++;
    if(j==i) {
      printf("The middle element is: %d\n", curr2->value);
      break;
    }
    curr2 = curr2->next;
  }
  
  return 0;
}