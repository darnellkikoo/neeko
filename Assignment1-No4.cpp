#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void remove(Node *curr) {
  Node *before = head;
  Node *after = curr->next;
  while(before->next != curr) {
    before = before->next;
  }
  before->next = after;
  free(curr);
}

void duplicate() {
  Node *curr = head;
    while (curr && curr->next != NULL){
        if (curr->value == curr->next->value){
            if (curr==head){
                popHead ();
            }else{
                remove (curr);
            }
        }
        curr = curr->next;
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
int main() {
  pushHead(1);
  pushHead(0);
  pushTail(1);
  pushTail(2);
  pushTail(3);
  pushTail(3);
  pushTail(4);
  pushTail(4);
  pushTail(4);
  pushTail(5);
  pushTail(5);
  pushTail(6);

  printf("Before removing the duplicate(s):\n");
  printLinkedList();
  duplicate();
  printf("After removing the duplicate(s):\n");
  printLinkedList();
  return 0;
}