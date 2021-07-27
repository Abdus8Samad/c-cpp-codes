#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int a = INT_MIN,b=a,c=a;
    for(int i=0;i<n;i++){
        // if(arr[i] <= d){
        //     e = d;
        //     d = arr[i];
        // } else if(arr[i] <= e) e = arr[i];
        if(arr[i] >= a){
            c = b;
            b = a;
            a = arr[i];
        } else if(arr[i] >= b){
            c = b;
            b = arr[i];
        } else if(arr[i] >= c) c = arr[i];
    }
    delete[] arr;
    cout << a << " " << b << " " << c << "\n";
    return 0;
}