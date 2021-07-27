#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

int main(){
    Node* a;
    printf("%d\n", a == NULL);
    Node* t;
    printf("%d\n", a == NULL);
    t = a;
    printf("%d\n", a == NULL);
}