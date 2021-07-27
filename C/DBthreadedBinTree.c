/* ---------- Double Threaded Binary Tree ---------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    struct treeNode *left, *right;
    int data, isLeftThread, isRightThread;
} treeNode;

treeNode* insert(treeNode* root, int data){
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isLeftThread = 0;
    newNode->isRightThread = 0;
    if(root == NULL) return newNode;
    if(data < root->data){
        if(!root->left || root->isLeftThread){
            newNode->right = root;
            newNode->isRightThread = 1;
            if(root->isLeftThread){
                newNode->left = root->left;
                newNode->isLeftThread = 1;
                root->isLeftThread = 0;
            }
            root->left = newNode;
        } else root->left = insert(root->left, data);
    } else {
        if(!root->right || root->isRightThread){
            newNode->left = root;
            newNode->isLeftThread = 1;
            if(root->isRightThread){
                newNode->right = root->right;
                newNode->isRightThread = 1;
                root->isRightThread = 0;
            }
            root->right = newNode;
        } else root->right = insert(root->right, data);
    }
    return root;
}

treeNode* leftMost(treeNode* root){
    if(!root) return NULL;
    while(root->left && root->isLeftThread == 0) root = root->left;
    return root;
}

treeNode* rightMost(treeNode* root){
    if(!root) return NULL;
    while(root->right && root->isRightThread == 0) root = root->right;
    return root;
}

treeNode* printInorder(treeNode* root){
    treeNode* temp = leftMost(root);
    while(temp){
        printf("%d ", temp->data);
        if(temp->isRightThread){
            temp = temp->right;
        } else {
            temp = leftMost(temp->right);
        }
    }
    printf("\n");
}

treeNode* printInorderRev(treeNode* root){
    treeNode* temp = rightMost(root);
    while(temp){
        printf("%d ", temp->data);
        if(temp->isLeftThread){
            temp = temp->left;
        } else {
            temp = rightMost(temp->left);
        }
    }
    printf("\n");
}

int main(){
    int x;
    treeNode* root = NULL;
    while(1){
        scanf("%d", &x);
        if(x == -1) break;
        root = insert(root, x);
    }
    printInorder(root);
    printInorderRev(root);
}

// Sample Input
// 20
// 10
// 16
// 14
// 17
// 30
// 5
// 13
// -1