// 1 2 3 4 5 6 7 8  9 ......
// 0 1 1 2 3 5 8 13 21 34 55 89
#include <iostream>

using ll = long long;

using namespace std;

ll fib1(ll n){
    if(n == 1 || n == 0) return 0;
    ll a = 0, b = 1, c = 1;
    for(ll i=3;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

ll fib2(ll n){
    ll* arr = new ll[n + 1];
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    for(ll i=3;i<=n;i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    ll ret = arr[n];
    delete[] arr;
    return ret;
}

/* Recursive */

ll helper(ll n, ll* arr){
    if(n == 1 || n == 0) return 0;
    if(arr[n] > 0) return arr[n];
    ll ret = helper(n - 1, arr) + helper(n - 2, arr);
    arr[n] = ret;
    return ret;
}

ll fib3(ll n){
    ll* arr = new ll[n + 1];
    for(int i=0;i<n;i++) arr[i] = 0;
    ll ret = helper(n, arr);
    delete[] arr;
    return ret;
}

// Slow
ll fib4(ll n){
    if(n == 2) return 1;
    if(n == 1 || n == 0) return 0;
    return fib4(n - 1) + fib4(n - 2);
}


int main(){
    ll n;
    cin >> n;
    cout << fib1(n) << "\n";
    cout << fib2(n) << "\n";
    cout << fib3(n) << "\n";
    cout << fib4(n) << "\n";
}