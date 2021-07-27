#include <iostream>

using namespace std;

int main(){
    int arr[] = {1,3,2,6,-3,-2,-5,-1,-1,-7,-4};
    int n = 11;
    int cnt = 0;
    for(int i=0;i<n;i++) if(arr[i] < 0) cnt++;
    int i = 0,j = cnt;
    while(j < n && i < n/2){
        if(arr[j] < 0 && arr[i] > 0){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        } else if(arr[j] < 0 && arr[i] < 0){
            i++;
        } else if(arr[j] > 0 && arr[i] < 0){
            i++;
            j++;
        } else {
            j++;
        }
    }
    for(int i=0;i<n;i++) cout << arr[i] << ", ";
}