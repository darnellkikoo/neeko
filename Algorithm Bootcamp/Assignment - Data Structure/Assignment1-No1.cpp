#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node1 {
  int value1;
  Node1 *next1;
}*head1 = NULL, *tail1 = NULL;

Node1 *createNode1(int value1) {
  Node1 *newNode1 = (Node1*)malloc(sizeof(Node1));
  newNode1->value1 = value1;
  newNode1->next1 = NULL;
  return newNode1;
}

void pushTail1(int value1) {
  Node1 *temp = createNode1(value1);
  if(!head1) {
    head1 = tail1 = temp;
  } else {
    tail1->next1 = temp;
    tail1 = temp;
  }
}
//pemisah stuck 1 dan 2
struct Node2 {
  int value2;
  Node2 *next2;
}*head2 = NULL, *tail2 = NULL;

Node2 *createNode2(int value2) {
  Node2 *newNode2 = (Node2*)malloc(sizeof(Node2));
  newNode2->value2 = value2;
  newNode2->next2 = NULL;
  return newNode2;
}

void pushTail2(int value) {
  Node2 *temp = createNode2(value);
  if(!head2) {
    head2 = tail2 = temp;
  } else {
    tail2->next2 = temp;
    tail2 = temp;
  }
}

//Node 3
struct Node3 {
  int value3;
  Node3 *next3;
}*head3 = NULL, *tail3 = NULL;

Node3 *createNode3(int value3) {
  Node3 *newNode3 = (Node3*)malloc(sizeof(Node3));
  newNode3->value3 = value3;
  newNode3->next3 = NULL;
  return newNode3;
}

void pushTail3(int value) {
  Node3 *temp = createNode3(value);
  if(!head3) {
    head3 = tail3 = temp;
  } else {
    tail3->next3 = temp;
    tail3 = temp;
  }
}

void printLinkedList() {
  Node3 *curr = head3;
  while(curr) {
    printf("%d->", curr->value3);
    curr = curr->next3;
  }
  printf("NULL\n");
}


int main() {
  int N=0, M=0;
  scanf("%d %d", &N, &M);

  //pushTail utk Node1
  for(int j=1; j<=N; j++) {
    int value=0;
    scanf("%d", &value);
    pushTail1(value);
  }

  //pushTail utk Node2
  for(int k=1; k<=M; k++) {
    int value=0;
    scanf("%d", &value);
    pushTail2(value);
  }
  Node2 *curr2 = head2;
  Node1 *curr1 = head1;
  Node3 *curr3 = head3;

  //merge node1 dan node2 skalian sorting
  while(curr1 && curr2) {
    if(curr1->value1 < curr2->value2) {
      pushTail3(curr1->value1);
      curr1 = curr1->next1;
    } else {
      pushTail3(curr2->value2);
      curr2 = curr2->next2;
    }
    
  }

  while(curr1) {
   pushTail3(curr1->value1);
    curr1 = curr1->next1;
    
  }

  while(curr2) {
   pushTail3(curr2->value2);
    curr2 = curr2->next2;
    
  }
  printLinkedList();
  return 0;
}