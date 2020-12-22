#include <stdio.h>
#include <stdlib.h>

struct Node {
  int ele;
  int flag;
  Node *next;
}*head = NULL, *tail = NULL;

Node *createNode(int ele) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->ele = ele;
  newnode->flag = 0;
  newNode->next = NULL;
  return newNode;
}

void pushTail(int ele) {
  Node *temp = createNode(ele);
  if(!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}


int main() {
  int boolean = 0;
  //assume linked list = node;
  Node *curr = head;

  // linked-list cycle check
  while(curr) {
    if(curr->flag == 0) {
      curr->flag = 1;
    } else {
      boolean = 1;
      break;
    }
    curr = curr->next;
  }
  if(boolean == 1) {
    printf("This LinkedList has a cycle\n");
  } else {
    printf("This LinkedList does not have any cycle\n");
  }
  return 0;
}