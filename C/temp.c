#include<stdio.h>

void fun(int arr[],int i,int j,int k,int n,int num,int*max)
{
    if(i==n)
        return;
    if(j==n)
    {
        fun(arr,i+1,i+1,k,n,0,max);
        return;
    }

    if (arr[i]+k>=arr[j])
        num++;
    if(num>*max)
        *max = num;
    fun(arr,i,j+1,k,n,num,max);
}

int main()
{
    int N,k;
    scanf("%d %d",&N,&k);
    int arr[N];
    int i;
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max =0;
    fun(arr,0,0,k,N,0,&max);
    printf("%d",max);
    return 0;
}