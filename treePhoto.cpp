#include <iostream>

// 1 2 4 7 8 11 12 13 17 18 19 20 21 25 27 32 33

using namespace std;

int mx = 1;

void func(int* arr, int n, int k, int st, int i, int ans){
    if(n == 1 || i > n - 1) return;
    if(arr[i] - arr[st] <= k) ans++;
    else{
        int j = st + 1;
        for(;j<i;j++){
            if(arr[i] - arr[j] <= k){
                st = j;
                break;
            }
        }
        if(j == i) st = j;
        ans = i - st + 1;
    }
    if(mx < ans) mx = ans;
    func(arr, n, k, st, i + 1, ans);
}

int main(){
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    func(arr, n, k, 0, 1, 1);
    delete[] arr;
    cout << mx << "\n";
}