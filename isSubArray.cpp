#include <iostream>

using namespace std;

bool subs(int par[], int s[], int n, int m){
    if(m > n) return false;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(cnt == m) return true;
        if(par[i] == s[cnt]) cnt++;
        else{
            if(cnt != 0) i--;
            cnt = 0;
        }
    }
    return cnt == m;
}

int main(){
    int arr1[] = {1,3,4,2,5,6,7,7,8,4};
    int arr2[] = {7, 8, 4};
    int n = sizeof(arr1)/4;
    int m = sizeof(arr2)/4;
    cout << subs(arr1, arr2, n, m);
}