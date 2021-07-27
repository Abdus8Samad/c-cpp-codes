typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct stack{
    Node* head;
} stack;

void initStack(stack* s){
    s->head = NULL;
}

void push(stack* s, int n){
    Node* toPush = (Node*)malloc(sizeof(Node));
    toPush->data = n;
    if(!s->head){
        toPush->next = NULL;
        s->head = toPush;
    }
    else {
        toPush->next = s->head;
        s->head = toPush;
    }
}

int isEmpty(stack* s){
    return s->head == NULL;
}

int top(stack* s){
    return s->head == NULL ? -1 : s->head->data;
}

int pop(stack* s){
    if(!s->head) return -1;
    Node* toDel = s->head;
    int ret = toDel->data;
    s->head = s->head->next;
    free(toDel);
    return ret;
}