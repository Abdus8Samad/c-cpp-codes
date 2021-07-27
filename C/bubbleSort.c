#include <stdio.h>

void bubbleSort(int* arr, int n){
    int i = 0;
    for(;i < n - 1;i++){
        int j = 0;
        for(;j < n - i - 1;j++){
            if(arr[j + 1] < arr[j]){
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {4, -2, 5, 6, 2, -5, 4, 3, 2, -7, 8, 45, 2, 24, 43, 23, 24, 43, 0, 0, 67, 54, 45};
    int i = 0, n = sizeof(arr) / 4;
    bubbleSort(arr, n);
    for(;i < n;i++){
        printf("%d, ", arr[i]);
    }
}