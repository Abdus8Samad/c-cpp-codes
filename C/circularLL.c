#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

void insert(int d){
    Node* toAdd = (Node*)malloc(sizeof(Node));
    toAdd->data = d;
    if(!head){
        head = toAdd;
        head->next = toAdd;
    } else {
        Node* temp = head;
        while(temp->next != head) temp = temp->next;
        temp->next = toAdd;
        toAdd->next = head;
    }
}

int pop(){
    if(!head) return -1;
    if(head->next == head){
        int ret = head->data;
        head = NULL;
        return ret;
    }
    Node* temp = head;
    while(temp->next->next != head) temp = temp->next;
    int ret = temp->next->data;
    Node* del = temp->next;
    temp->next = head;
    free(del);
    return ret;
}

int removeFromPos(int pos){
    if(pos <= 0) return -1;
    Node* temp = head;
    if(pos == 1){
        int ret = head->data;
        if(head->next == head) head = NULL;
        else {
            while(temp->next != head) temp = temp->next;
            Node* d = temp->next;
            temp->next = temp->next->next;
            free(d);
            head = temp->next;
        }
        return ret;
    } else {
        int cnt = pos - 2;
        while(cnt-- && temp->next != head) temp = temp->next;
        if(cnt > 0) return -1;
        Node* d = temp->next;
        int ret = d->data;
        temp->next = temp->next->next;
        free(d);
        return ret;
    }
}

void printList(){
    Node* temp = head;
    int c = 1;
    while(temp != head || c){
        c = 0;
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

void reverseList(){
    if(!head || head->next == head) return;
    Node* temp = head->next;
    Node* prev = head;
    Node* next = temp;
    while(temp != head){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    temp->next = prev;
    head = prev;
}

Node* reverseListRecurr(Node* temp){
    if(!temp || temp->next == head) return temp;
    Node* temp2 = temp->next;
    Node* h = reverseListRecurr(temp2);
    temp2->next = temp;
    temp->next = h;
    return h;
}

void insertAtPos(int pos){
    if(pos <= 0) return;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int temp;
        scanf("%d", &temp);
        insert(temp);
    }
    printList();
    head = reverseListRecurr(head);
    printList();
    reverseList();
    printList();
}