typedef struct stack{
    int capacity;
    int top;
    int* arr;
} stack;

stack* createStack(int n){
    stack* newStack = (stack*)malloc(sizeof(stack));
    newStack->arr = (int*)malloc(n * 4);
    newStack->capacity = n;
    newStack->top = -1;
    return newStack;
}

int top(stack* st){
    if(st->top == -1){
        printf("Stack Is Empty\n");
        return -1;
    }
    return *(st->arr + st->top);
}

int isFull(stack* st){
    return st->top == st->capacity - 1;
}

void push(stack* st, int n){
    if(isFull(st)){
        printf("StackOverflow\n");
        return;
    }
    *(st->arr + ++st->top) = n;
}

int isEmpty(stack* st){
    return st->top == -1;
}

int pop(stack* st){
    if(isEmpty(st)){
        printf("Stack Is Empty\n");
        return -1;
    }
    int ret = *(st->arr + st->top);
    *(st->arr + st->top--) = -1;
    return ret;
}