#include <iostream>

using namespace std;

int kthSmallest(int* arr, int l, int r, int k){
    int a = 0,ans = arr[l],trk;
    for(int i=l+1;i<=r;i++){
        if(arr[i] < ans){
            if(a == k - 1){
                trk = arr[i];
            } else if(a == k){
                ans = trk;
                if(arr[i] < ans) k = 1;
                else k = 0;
            } else {
                a++;
            }
        }
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    cout << kthSmallest(arr, 0, n - 1, k) << "\n";
}