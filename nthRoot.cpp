#include <iostream>
#include <math.h>

using namespace std;

// 14 268435456

int pw(int n, int k, int m){
    if(k == 1) return n;
    int p = pw(n, k - 1, m);
    if(n * p % 1000000007 != n * p || n * p > m) return 0;
    return (n * p);
}
int binSrch(int n, int s, int e, int m){
    if(s > e) return -1;
    int mid = (s + e) / 2, p = pw(mid, n, m);
    if(p == m) return mid;
    else if(p > m || p <= 0) return binSrch(n, s, mid - 1, m);
    else return binSrch(n, mid + 1, e, m);
}

int NthRoot(int n, int m){
    return binSrch(n, 1, m, m);
}  

int main(){
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m) << "\n";
}