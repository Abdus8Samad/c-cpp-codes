#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

void printList(Node* head){
    Node* temp = head;
    while(temp){
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* swapNodes(Node* head, int a){
    if(a == 1){
        Node* b = head->next;
        head->next = b->next;
        b->next = head;
        return b;
    } else {
        Node* b = head->next->next;
        head->next->next = NULL;
        b->next = head->next;
        head->next = b;
    }
    return head;
}

void jumble(Node* head){
    printList(head);
    head = swapNodes(head, 0);
    printList(head);
}

// Function to run for output
void printPerm(Node* head){
    jumble(head);
    head = swapNodes(head, 1);
    jumble(head);
    head = swapNodes(head, 1);
    jumble(head);
    // to Retain Original Linked List
    swapNodes(head , 1);
}

int main(){
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    Node* c = (Node*)malloc(sizeof(Node));
    a->data = 'R';
    b->data = 'S';
    c->data = 'T';
    a->next = b;
    b->next = c;
    c->next = NULL;
    printPerm(a);
    printList(a);
}