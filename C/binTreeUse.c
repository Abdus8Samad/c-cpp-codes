#include <stdio.h>
#include <stdlib.h>
#include "binTree.h"

int main(){
    treeNode* root = buildtree();
    printTree(root);
    printTree(invertTree(root));
}