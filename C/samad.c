#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int* array;
    unsigned capacity;
};
struct stack* create(unsigned capacity){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity=capacity;
    s->array=(int*)malloc(capacity*sizeof(int));
    return s;
}
void push(struct stack* s,int data){
    if(s->top == s->capacity - 1){
        return;
    }
    s->array[++s->top]=data;
    printf("stack me push %d\n",s->array[s->top]);
}
int pop(struct stack* s){
    if(s->top < 0) return -1;
    return s->array[s->top--];
}
int peek(struct stack* s){
  if(s->top >= 0){
    return s->array[s->top];
  }
  return -1;
}

int main(){
    struct stack* st = create(5);
    printf("%d\n", peek(st));
    push(st, 1);
    push(st, 2);
    push(st, 3);
    push(st, 4);
    push(st, 5);
    push(st, 6);
    printf("%d\n", peek(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", pop(st));
    printf("%d\n", peek(st));
}