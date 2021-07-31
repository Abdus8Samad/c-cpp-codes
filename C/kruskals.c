#include <stdio.h>
#include <stdlib.h>

int main(){
    int v, e;
    scanf("%d %d", &v, &e);
    int* parents = (int*)malloc(4 * v);
    int* visited = (int*)malloc(4 * v);
    for(int i = 0;i < v;i++){
        parents[i] = i;
        visited[i] = 0;
    }
    int cnt = 0;
    free(parents);
    free(visited);
}