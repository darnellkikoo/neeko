#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Node 1
struct Node {
  char name[255];
  int value;
  Node *next;
}*head = NULL, *tail = NULL;

Node *createNode(int value) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode-> value = value;
  newNode-> next = NULL;
  return newNode;
}

void pushHead(int value) {
  Node *temp = createNode(value);
  if(!head) {
    head = tail = temp;
  } else {
    temp->next = head; // node setelah temp adalah head
    head = temp; // head baru adalah temp
  }
}

void pushTail(int value) {
  Node *temp = createNode(value); // buat nodenya

  if(!head) { // linked list kosong ( 0 node )
    head = tail = temp; //temp akan menjadi head dan tail
  } else { // >= 1 node
    tail->next = temp;
    tail = temp; // temp akan menjadi tail (node terakhir)
  }
}
void popHead(){
  if(!head) {
    return;
  } else if(head == tail) {
    head = tail = NULL;
    free(head);
  } else {
    Node *temp = head;
    head = temp->next;
    temp->next = NULL;
    free(temp);
  }
}

void popTail (){
    if (!head){
        return;
    }
    else if (head==tail){
        head = tail = NULL;
        free(head);
    }
    else {
        Node *temp = head; 
        while (temp->next != tail){
            temp = temp->next;
        }           
        temp->next = NULL;
        free(tail);
        tail = temp; 
    }
}

//Node 2
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

void popHead2(){
  if(!head2) {
    return;
  } else if(head2 == tail2) {
    head2 = tail2 = NULL;
    free(head2);
  } else {
    Node2 *temp = head2;
    head2 = temp->next2;
    temp->next2 = NULL;
    free(temp);
  }
}

void popTail2 (){
    if (!head2){
        return;
    }
    else if (head2==tail2){
        head2 = tail2 = NULL;
        free(head2);
    }
    else {
        Node2 *temp = head2; 
        while (temp->next2 != tail2){
            temp = temp->next2;
        }           
        temp->next2 = NULL;
        free(tail2);
        tail2 = temp; 
    }
}

void putar() {
  Node *curr = head;
  Node *akhir = tail;
  int flag = 0;
  while(curr->next != akhir) {
    curr = curr->next;
  }

  while(flag == 0) {
    pushTail2(akhir->value);
    akhir = curr;
    if(akhir!= head) {
      curr = head;
      while(curr->next != akhir) {
        curr = curr->next;
      }
    } else {
      pushTail2(curr->value);
      flag = 1;
    }

  }
}

void printLinkedList() {
  Node *curr = head;
  while(curr) {
    printf("%d ->", curr->value);
    curr = curr->next;
  }
  printf("NULL\n");
}
void printLinkedList2() {
  Node2 *curr = head2;
  while(curr) {
    printf("%d -> ", curr->value2);
    curr = curr->next2;
  }
  printf("NULL\n");
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
  printLinkedList();
  putar();
  printLinkedList2();

}