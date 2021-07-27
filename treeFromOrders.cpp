#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data = -1;
        left = NULL;
        right = NULL;
    }
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node* root){
    if(!root) return;
    cout << root->data << ": L ";
    if(root->left) cout << root->left->data;
    cout << " R ";
    if(root->right) cout << root->right->data;
    cout << "\n";
    printTree(root->left);
    printTree(root->right);
}

Node* postIn(int post[], int in[], int postS, int postE, int inS, int inE){
    if(postS > postE || inS > inE) return NULL;
    if(inS == inE || postS == postE){
        Node* ret = new Node(in[inS]);
        return ret;
    }
    Node* root = new Node(post[postE]);
    int pos;
    for(int i=inS;i<=inE;i++){
        if(in[i] == post[postE]){
            pos = i;
            break;
        }
    }
    root->left = postIn(post, in, postS, postS + pos - inS - 1, inS, pos - 1);
    root->right = postIn(post, in, postS + pos - inS, postE - 1,  pos + 1, inE);
    return root;
}

Node* preIn(int pre[], int in[], int preS, int preE, int inS, int inE){
    if(preS > preE || inS > inE) return NULL;
    if(inS == inE || preS == preE){
        Node* ret = new Node(in[inS]);
        return ret;
    }
    Node* root = new Node(pre[preS]);
    int pos;
    for(int i=inS;i<=inE;i++){
        if(in[i] == pre[preS]){
            pos = i;
            break;
        }
    }
    root->left = preIn(pre, in, preS + 1, preS + pos - inS, inS, pos - 1);
    root->right = preIn(pre, in, preS + pos - inS + 1, preE,  pos + 1, inE);
    return root;
}


int main(){
    int post[] = {7, 12, 11, 9, 5, 2, 3, 6, 8};
    int pre[] = {8, 5, 7, 9, 12, 11, 6, 3, 2};
    int in[] = {7, 5, 12, 9, 11, 8, 6, 2, 3};
    // printTree(postIn(post, in, 0, 8, 0, 8));
    printTree(preIn(pre, in, 0, 8, 0, 8));
}