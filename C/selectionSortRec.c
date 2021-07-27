#include <stdio.h>

void swap(int* a, int* b){
    int c = *b;
    *b = *a;
    *a = c;
}

void selectionSort(int* arr, int i, int j, int n, int min){
    if(i == n) return;
    if(j == n){
        swap(arr + min, arr + i);
        i++;
        min = i;
        j = i;
    }
    if(arr[j] < arr[min]) min = j;
    selectionSort(arr, i, j + 1, n, min);
}

int main(){
    int arr[22] = {-2, 4, -2, 1, 3, 5, 6, 3, -4, 5, -2, 9, 0, 23, 44, 1, 11, 32, -23, 0, -22, 11};
    int n = sizeof(arr) / 4;
    selectionSort(arr, 0, 0, n, 0);
    for(int i=0;i<22;i++) printf("%d ", arr[i]);
}