typedef struct Node{
    int data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createTree(int d){
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = d;
    root->firstChild = NULL;
    root->nextSibling = NULL;
    return root;
}

Node* 