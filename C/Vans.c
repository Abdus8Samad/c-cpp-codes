#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int empty(struct stack* ptr)
{
    if(ptr->top==-1){return 1;}
    return 0;
}

void push(struct stack* st,char x)
{
    if(st->top==st->size-1){printf("Stack overflow\n");}
    st->top++;
    st->arr[st->top]=x;
}

void pop(struct stack* ptr){ptr->top--;}

char stack_top(struct stack* ptr)
{
    return ptr->arr[ptr->top];
}

int parenthesisMatch(char exp[], int n)
{
    struct stack* ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->size=n;
    ptr->top=-1;
   for(int i=0;i<n;i++)
   {
       if(exp[i]=='('|| exp[i]=='['|| exp[i]=='{')
       {
          push(ptr,exp[i]);
       }
       if(exp[i]==')' || exp[i]=='}'|| exp[i]==']')
       {
           if(empty(ptr)|| stack_top(ptr)!=exp[i])
           {
               return -1;
           }
           else{pop(ptr);}
       }
       i++;  
   }
   if(!empty(ptr)){return -1;}
   return 1;
}

int main()
{
    char exp[]="(){}";
    int n=strlen(exp);
    int x= parenthesisMatch(exp,n);
    if(x=1){printf("it's balanced");}
    else{printf("not balanced");}
}