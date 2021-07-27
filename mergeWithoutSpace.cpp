#include <iostream>

using namespace std;

void merge(int arr[], int s, int e){
    if(s >= e) return;
    
}

int main(){
    int arr[] = {4, -3, 6, 6, 4, 8, 11, -4, -8, 3, 1, 7};
    int n = sizeof(arr) / 4;
    merge(arr, 0, n - 1);
    for(int i=0;i<n;i++) cout << arr[i] << ", ";
}