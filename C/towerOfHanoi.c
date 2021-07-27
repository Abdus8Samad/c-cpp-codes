#include <stdio.h>

int i;

void printSteps(int n, char src, char aux, char dest){
    if(n > 0){
        printSteps(n - 1, src, dest, aux);
        printf("Move disc %d from %c to %c using %c\n", i - n + 1, src, dest, aux);
        printSteps(n - 1, aux, src, dest);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    i = n;
    printSteps(n, 'A', 'B', 'C');
}