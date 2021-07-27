/* ---------- All Tree Traversals With And Without Recursion ---------- */
#include <stdio.h>
#include <stdlib.h>
#include "binTree.h"
#define STACK_SIZE 30 

treeNode* stack[STACK_SIZE];

void preOrderRec(treeNode* root){
    if(!root) return;
    printf("%d ", root->data);
    preOrderRec(root->left);
    preOrderRec(root->right);
}

void preOrder(treeNode* root){
    if(!root) return;
    int top = 1;
    stack[0] = root;
    while(top){
        treeNode* temp = stack[--top];
        printf("%d ", temp->data);
        if(temp->right) stack[top++] = temp->right;
        if(temp->left) stack[top++] = temp->left;
    }
}

void postOrder(treeNode* root){
    if(!root) return;
    int arr[30], cnt = 0;
    int top = 1;
    stack[0] = root;
    while(top){
        treeNode* temp = stack[--top];
        arr[cnt++] = temp->data;
        if(temp->left) stack[top++] = temp->left;
        if(temp->right) stack[top++] = temp->right;
    }
    for(int i = cnt - 1;i >= 0;i--) printf("%d ", arr[i]);
}

void postOrderRec(treeNode* root){
    if(!root) return;
    postOrderRec(root->left);
    postOrderRec(root->right);
    printf("%d ", root->data);
}

void inOrderRec(treeNode* root){
    if(!root) return;
    inOrderRec(root->left);
    printf("%d ", root->data);
    inOrderRec(root->right);
}

void inOrder(treeNode* root){
    if(!root) return;
    treeNode* curr = root;
    int top = 0;
    while(top || curr){
        while(curr){
            stack[top++] = curr;
            curr = curr->left;
        }
        curr = stack[--top];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

int main(){
    treeNode* root = buildtree();
    printf("\n");
    printTree(root);
    printf("\n");
    printf("inorderRec: ");
    inOrderRec(root);
    printf("\n");
    printf("inorder:    ");
    inOrder(root);
    printf("\n");
    printf("preorderRec: ");
    preOrderRec(root);
    printf("\n");
    printf("preorder:    ");
    preOrder(root);
    printf("\n");
    printf("postorderRec: ");
    postOrderRec(root);
    printf("\n");
    printf("postorder:    ");
    postOrder(root);
    printf("\n");
}
// Sample Input
// 1
// lr
// 2
// lr
// 3
// 00
// 4
// 00
// 5
// lr
// 6
// 00
// 7
// 00