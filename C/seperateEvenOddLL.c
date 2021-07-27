#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printList(Node* head){
    Node* temp = head;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* seperateEvenOdd(Node* head){
    if(!head || !head->next) return NULL;
    Node* ret = head->next, *temp = head, *t = temp->next;
    while(t && temp){
        temp->next = temp->next->next;
        temp = temp->next;
        if(t->next) t->next = t->next->next;
        t = t->next;
    }
    return ret;
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL, *tail = NULL;
    while(n--){
        int temp;
        scanf("%d", &temp);
        Node* toAdd = (Node*)malloc(sizeof(Node));
        toAdd->data = temp;
        toAdd->next = NULL;
        if(!head){
            tail = toAdd;
            head = toAdd;
        }
        else {
            tail->next = toAdd;
            tail = toAdd;
        }
    }
    printList(head);
    Node* even = seperateEvenOdd(head);
    printList(head);
    printList(even);
}