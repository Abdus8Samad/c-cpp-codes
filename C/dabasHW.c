#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node* next;
} Node;

void swap(Node *A, Node *B)
{
    int temp = B->data;
    B->data = A->data;
    A->data = temp;
}
void print(Node *head)
{
    while (head != NULL)
    {
        printf("%c", head->data);
        head = head->next;
    }
    printf("\n");
}
void jumble(Node *head, Node *temp)
{
    //fix temp and jumble the rest
    if(temp->next==NULL)
       {
       print(head);
       return;
       }
    jumble(head,temp->next);
    Node* swapper = temp->next;
    while(swapper!=NULL)
    {
        swap(temp,swapper);
        jumble(head,temp->next);
        swap(temp,swapper);
        swapper = swapper->next;
    }
}

int main(){
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    Node* c = (Node*)malloc(sizeof(Node));
    Node* d = (Node*)malloc(sizeof(Node));
    Node* e = (Node*)malloc(sizeof(Node));
    a->data = 'A';
    b->data = 'B';
    c->data = 'C';
    d->data = 'D';
    e->data = 'E';
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    jumble(a, a);
}