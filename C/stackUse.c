#include <stdio.h>
#include <stdlib.h>
#include "stackUsingLL.h"

void printStack(stack* s){
    if(isEmpty(s)) return;
    char t = pop(s);
    printf("%c ", t);
    printStack(s);
    push(s, t); 
}

int main(){
    stack* s = (stack*) malloc(sizeof(stack));
    initStack(s);
    push(s, '1');
    push(s, '2');
    push(s, '3');
    push(s, '4');
    push(s, '5');
    while(!isEmpty(s)) printf("%c ", pop(s));
    // printStack(s);
}