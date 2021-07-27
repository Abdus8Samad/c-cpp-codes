#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackUsingLL.h"
#include "binTree.h"

int precedence(char a){
    if(a == '^') return 2;
    if(a == '*'|| a == '/') return 1;
    if(a == '+' || a == '-') return 0;
    else return 3;
}

int isOperator(char c){
    return (c == '-' || c == '+' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char* infix){
    stack* st = (stack*)malloc(sizeof(stack));
    initStack(st);
    for(int i=0;i<strlen(infix);i++){
        char c = infix[i], t = top(st);
        if(c == '(') push(st, '(');
        else if(c == ')'){
            while(!isEmpty(st) && top(st) != '('){
                char p = pop(st);
                if(isOperator(p)) printf("%c", p);
            }
            pop(st);
        }
        else if(isOperator(c)){
            if(isEmpty(st) || t == '(' || precedence(t) < precedence(c)) push(st, c);
            else {
                while(!isEmpty(st) && top(st) != '(' && precedence(c) <= precedence(top(st))){
                    char p = pop(st);
                    if(isOperator(p)) printf("%c", p);
                }
                push(st, c);
            }
        }
        else printf("%c", c);
    }
    while(!isEmpty(st)) printf("%c", pop(st));
    printf("\n");
}

treeNode* createExtTree(char* s, int st, int e){
    treeNode* root = (treeNode*)malloc(sizeof(treeNode));
    if(st >= e){
        root->left = NULL;
        root->right = NULL;
        root->data = s[st];
        return root;
    }
    int minPrec = st;
    for(int i = st + 1;i <= e;i++){
        if(isOperator(s[i]) && precedence(s[i]) <= precedence(s[minPrec])) minPrec = i;
    }
    root->data = s[minPrec];
    root->left = createExtTree(s, st, minPrec - 1);
    root->right = createExtTree(s, minPrec + 1, e);
    return root;
}

// Extended Binary Tree Approach (Bracket not handled)
void helper(treeNode* root, char* s){
    if(!root->left && !root->right){
        s[0] = root->data;
        s[1] = '\0';
        return;
    }
    char leftCall[100];
    char rightCall[100];
    helper(root->left, leftCall);
    helper(root->right, rightCall);
    int cnt = 0;
    for(int i = 0;leftCall[i];i++) s[cnt++] = leftCall[i];
    for(int i = 0;rightCall[i];i++) s[cnt++] = rightCall[i];
    s[cnt++] = root->data;
    s[cnt] = '\0';
}
void inToPost(char s[]){
    treeNode* t = createExtTree(s, 0, strlen(s) - 1);
    char* p = (char*)malloc(100);
    p = realloc(p, strlen(p) + 1);
    helper(t, p);
    printf("%s\n", p);
}

int main(){
   char infix[100];
   scanf("%s", infix);
   infixToPostfix(infix);
   inToPost(infix);
}
// ((A+B)*C-D)*E
// A-B/C^D+E*F