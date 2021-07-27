#include<stdio.h>
#include<string.h>

int index_of_string(char str[],char s[]);
int main()
{
    int index;
    index = index_of_string("abababbbaabbababbbaa","aabb");
     if (index ==-1)
     {
         printf("substring is not present\n ");
     }   
    else
        printf("substring found at %d\n",index);
     
     return 0;   
}

int index_of_string(char str[],char s[])
{
    int i,j,k,l;
    l=strlen(s);
    for(i=0;str[i+l-1]; i++)
    {
        k=0;
        for(j=i;j<=i+l-1;j++){
            if(str[j] !=s[k]) break;
            k++;
        }
        if(k==l) return i;
    }
    return (-1);
}