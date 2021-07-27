#include <stdio.h>

int binSearch(int* arr, int s, int e, int k){
    if(s > e) return -1;
    int mid = (s + e) / 2;
    if(arr[mid] == k) return mid;
    if(arr[mid] > k) return binSearch(arr, s, mid - 1, k);
    if(arr[mid] < k) return binSearch(arr, mid + 1, e, k);
}

int main(){
    int arr[] = {-4, 5, 7, 12, 23, 45, 65, 222, 321, 1023, 3452, 4532, 34523, 66453};
    int i = 0, n = sizeof(arr) / 4;
    printf("%d\n", binSearch(arr, 0, n - 1, 23));
    printf("%d\n", binSearch(arr, 0, n - 1, 333));
}