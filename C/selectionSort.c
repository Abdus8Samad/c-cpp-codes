#include <stdio.h>

void selectionSort(int* arr, int n){
    int i = 0;
    for(;i < n;i++){
        int mn = arr[i];
        int j = i, ind = i;
        for(;j < n;j++){
            if(arr[j] < mn){
                mn = arr[j];
                ind = j;
            }
        }
        int temp = arr[ind];
        arr[ind] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[] = {4, -2, 5, 6, 2, -5, 4, 3, 2, -7, 8, 45, 2, 24, 43, 23, 24, 43, 0, 0, 67, 54, 45};
    int i = 0, n = sizeof(arr) / 4;
    selectionSort(arr, n);
    for(;i < n;i++){
        printf("%d, ", arr[i]);
    }
}