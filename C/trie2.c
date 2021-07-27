#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct trie
{
    struct trie *child[26];
    int endofwrd;
};


struct trie *getnode(void){
    struct trie *pnode;
    int i;
    pnode=(struct trie*)malloc(sizeof(struct trie));
    pnode->endofwrd=0;
    for(i=0; i<26;i++)
        pnode->child[i]=NULL;
    return pnode;
}


void insert(struct trie *root, char s[])
{
    struct trie *p;
    p=root;
    int n,i,k;
    n=strlen(s);
    for(i=0; i<n;i++){
        k = s[i] - 'a';
        if (p->child[k] == NULL)
            p->child[k]=getnode();
        p=p->child[k];
    }
    p->endofwrd=1;
}


int search(struct trie *root, char s[])
{
    struct trie *p=root;
    int n, i, k;
    n= strlen(s);
    for(i=0; i<n;i++){
        k = s[i] - 'a';
        if (p->child[k] == NULL)
            return 0;
        p = p->child[k];
    }
    if ((p != NULL) && (p->endofwrd == 1))
    return 1;
}

int isNodeEmpty(struct trie* root){
    int i = 0;
    for(; i < 26;i++){
        if(root->child[i]) return 0;
    }
    return 1;
}

void removeWord(struct trie* root, char s[]){
    if(!root) return;
    if(s[0] == '\0'){
        root->endofwrd = 0;
        return;
    }
    int i = 0, k = s[0] - 'a';
    if(!root->child[k]) return;
    removeWord(root->child[k], s + 1);
    if(isNodeEmpty(root->child[k]) && root->child[k]->endofwrd == 0){
        free(root->child[k]);
        root->child[k] = NULL;
    }
}

int main()
{
    struct trie root;
    root.endofwrd = 0;
    for(int i=0; i<26;i++)
        root.child[i]=NULL;
    char ins[20][100] = {
        // {"edadn"}, {"wujvu"}, {"oyrev"}, {"tmmft"}, {"vhnva"}, {"dytrx"}, {"xxaxc"}, {"qvzzr"}, {"tprkt"}, {"ofgbk"}
        {"oyrev"}, {"ofgbk"}
    };
    for(int i=0;i<2;i++){
        insert(&root, ins[i]);
    }
    printf("Word %s is %d\n", "oyrev", search(&root, "oyrev"));
    printf("Word %s is %d\n", "ofgbl", search(&root, "ofgbl"));
    printf("Word %s is %d\n", "ofgbk", search(&root, "ofgbk"));
    removeWord(&root, "ofgbk");
    printf("Word %s is %d\n", "oyrev", search(&root, "oyrev"));
    printf("Word %s is %d\n", "ofgbl", search(&root, "ofgbl"));
    printf("Word %s is %d\n", "ofgbk", search(&root, "ofgbk"));
    // for(int i=0;i<10;i++){
    //     printf("Word %s is %d\n", ins[i], search(root, ins[i]));
    // }
    return 0;
}