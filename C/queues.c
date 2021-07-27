#include <stdio.h>
#include <stdlib.h>

struct queue{
    int rear;
    int front;
    int* arr;
};

struct queue* createQueue(int n){
    struct queue* newQueue = (struct queue*)malloc(sizeof(struct queue));
    newQueue->arr = (int*)malloc(4 * n);
    newQueue->rear = -1;
    newQueue->front = -1;
    return newQueue;
}

int isFull(struct queue* q){
    return q->front == 0;
}

void enqueue(struct queue* q, int n){
    if(isFull(q)){
        printf("Queue Is Already Full\n");
        return;
    }
    *(q->arr + --q->front) = n;
}

int isEmpty(struct queue* q){
    return q->front == q->rear + 1;
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Is Empty\n");
        return -1;
    }
    int ret = *(q->arr + q->front);
    *(q->arr + q->front++) = -1;
    return ret;
}

int front(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Is Empty\n");
        return -1;
    }
    return *(q->arr + q->front);
}

int rear(struct queue* q){
    if(isEmpty(q)){
        printf("Queue Is Empty\n");
        return -1;
    }
    return *(q->arr + q->rear);
}

int main(){
    struct queue* q = createQueue(5);
    printf("%d\n", front(q));
    printf("%d\n", rear(q));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 1);
    printf("%d\n", front(q));
    printf("%d\n", rear(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", front(q));
    printf("%d\n", rear(q));
}