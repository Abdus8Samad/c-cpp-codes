#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* s = calloc(100, 1);
    scanf("%s", s);
    s = realloc(s, strlen(s) + 1);
    int i = 0,b = 0,a = 0;
    for(;s[i];i++){
        if(i == 0 && (int) s[i] >= 97) b = 1;
        else if((int) s[i] < 97) a++;
    }
    i = 0;
    if(b == 1 && a == strlen(s) - 1 || a == strlen(s)){
        for(;s[i];i++){
            if((int) s[i] < 97) s[i] += 32;
            else s[i] -= 32;
        }
    }
    printf("%s\n", s);
    free(s);
}