#include <stdio.h>
#include <stdlib.h>

typedef struct cirQueue{
    int* arr;
    int capacity;
    int front;
    int rear;
} cQueue;

cQueue* createQueue(int capacity){
    cQueue* c = (cQueue*)malloc(sizeof(cQueue));
    c->capacity = capacity;
    c->front = -1;
    c->rear = -1;
    c->arr = (int*)malloc(4 * capacity);
    return c;
}

void enqueue(cQueue* c, int data){
    if((c->rear + 1) % c->capacity == c->front){
        printf("Queue is Full\n");
        return;
    }
    if(c->front == -1) c->front = 0;
    c->rear = (c->rear + 1) % c->capacity;
    *(c->arr + c->rear) = data;
}

int dequeue(cQueue* c){
    if(c->front == -1){
        printf("Queue is Empty\n");
        return -1;
    }
    int ret = *(c->arr + c->front);
    if(c->front == c->rear){
        c->front = -1;
        c->rear = -1;
    }
    else c->front = (c->front + 1) % c->capacity;
    return ret;
}

int front(cQueue* c){
    if(c->front == -1){
        printf("Queue is Empty\n");
        return -1;
    }
    return *(c->arr + c->front);
}

void print(cQueue* c){
    if(c->front == -1) return;
    for(int i = c->front;i <= c->rear;i = (i + 1) % c->capacity){
        printf("%d ", *(c->arr + i));
        if(i == c->rear) break;
    }
    printf("\n");
}

int main(){
    cQueue* c = createQueue(5);
    int n = 1;
    while(n){
        int x;
        printf("Enter X: ");
        scanf("%d", &x);
        if(x == 1){
            int t;
            printf("Enter Data To Enqueue: ");
            scanf("%d", &t);
            enqueue(c, t);
        } else if(x == 2){
            int t = dequeue(c);
            printf("Dequeue: %d\n", t);
        } else {
            print(c);
        }
        printf("Want to Continue ?: ");
        scanf("%d", &n);
    }
}