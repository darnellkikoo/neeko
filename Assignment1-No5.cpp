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

void pushHead(int value) {
  Node *temp = createNode(value);
  if(!head) {
    head = tail = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void printLinkedList() {
  Node *curr = head;
  while(curr) {
    printf("%d -> ", curr->value);
    curr = curr->next;
  }
  printf("NULL\n");
}

void find(int number) {
  Node *curr = head;
  int i = 0;
  while(curr) {
    i++;
    curr = curr->next;
  }
  i = i - number + 1;
  int j = 0;
  Node *curr2 = head;
  int result = 0;
  while(curr2) {
    j++;
    if(j == i) {
      result = curr2->value;
      break;
    }
    curr2 = curr2->next;
  }

  // print the Nth Node
  if(number%10 == 1)
  printf("The %dst node from the end of the linked list is: %d\n", number, result);
  else if(number%10 == 2)
   printf("The %dnd node from the end of the linked list is: %d\n", number, result); 
  else if(number%10 == 3) 
  printf("The %drd node from the end of the linked list is: %d\n", number, result); 
  else  printf("The %dth node from the end of the linked list is: %d\n", number, result);   
}


int main() {
  
  pushTail(1);
  pushTail(2);
  pushTail(3);
  pushTail(4);  
  pushTail(5);
  pushTail(6);  
  pushTail(7);
  pushTail(8);
  pushTail(9);
  pushTail(10);
  pushHead(0);
  printLinkedList();
  find(5);
  find(3);
  find(1);  

  
  return 0;
}