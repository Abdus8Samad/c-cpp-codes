#include <stdio.h>

void swap(int* a, int* b){
    int c = *b;
    *b = *a;
    *a = c;
}

void bubbleSort(int* arr, int j, int i){
    if(i == 0) return;
    if(j == i){
        j = 0;
        i--;
    }
    if(arr[j] > arr[j + 1]) swap(arr + j, arr + j + 1);
    bubbleSort(arr, j + 1, i);
}

int main(){
    int arr[22] = {-2, 4, -2, 1, 3, 5, 6, 3, -4, 5, -2, 9, 0, 23, 44, 1, 11, 32, -23, 0, -22, 11};
    int n = sizeof(arr) / 4;
    bubbleSort(arr, 0, n - 1);
    for(int i=0;i<22;i++) printf("%d ", arr[i]);
}