typedef struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* buildtree(){
    int temp;
    scanf("%d ", &temp);
    treeNode* rootNode = (treeNode*)malloc(sizeof(treeNode));
    rootNode->data = temp;
    rootNode->right = NULL;
    rootNode->left = NULL;
    char l, r;
    scanf("%c %c", &l, &r);
    if(l != '0') rootNode->left = buildtree();
    if(r != '0') rootNode->right = buildtree();
    return rootNode;
}

void printTree(treeNode* root){
    if(!root) return;
    printf("%d: ", root->data);
    if(root->left) printf("%d, ", root->left->data);
    if(root->right) printf("%d", root->right->data);
    printf("\n");
    printTree(root->left);
    printTree(root->right);
}

treeNode* invertTree(treeNode* root){
    if(!root) return NULL;
    treeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}