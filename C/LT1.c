#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void printList(Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteAtPos(Node** headRef, Node* head, int pos){
    if(pos <= 0 || !head){
        printf("%d is <= 0 or list is empty\n", pos);
        return;
    }
    if(pos == 1){
        (*headRef) = head->next;
        free(head);
        return;
    }
    int cnt = pos - 1;
    while(head && --cnt) head = head->next;
    if(cnt != 0){
        printf("%d is greater than the size of list\n", pos);
        return;
    }
    printf("Delete %d position Node\n", pos);
    Node* temp = head->next;
    head->next = head->next->next;
    if(temp) free(temp);
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
            head = toAdd;
            tail = head;
        } else {
            tail->next = toAdd;
            tail = toAdd;
        }
    }
    printList(head);
    deleteAtPos(&head, head, 1);
    printList(head);
    deleteAtPos(&head, head, 4);
    printList(head);
    deleteAtPos(&head, head, 8);
    printList(head);
    deleteAtPos(&head, head, 2);
    printList(head);
    deleteAtPos(&head, head, 5);
    printList(head);
    deleteAtPos(&head, head, -3);
    printList(head);
}