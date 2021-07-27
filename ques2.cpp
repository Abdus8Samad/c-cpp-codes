// aabaabbbab
// aaaaaaaabbbaaaaaaaabbbbbaaaaaabbaaaaaa
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int a = 0, b = 0,k,bm = 0,bmi;
    int mx = 0,mxi;
    cin >> s;
    cin >> k;
    int arr[26] = {};
    for(int i=0;i<s.length();i++){
        arr[s[i]-97]++;
        if(arr[s[i]-97] >= mx){
            mx = arr[s[i]-97];
            mxi = i;
        }
    }
    for(int i = 0;i<s.length();i++){
        if(s[i] == s[mxi]) b++;
        else b--;
        if(b >= bm){
            bm = b;
            bmi = i;
        }
    }
    int i = bmi;
    b = 0;
    while(k){
        if(s[i] != s[mxi]) k--;
        if(i == 0) break;
        b++;
        i--;
    }
    while(s[i] == s[mxi]){
        b++;
        if(i == 0) break;
        i--;
    }
    cout << b << "\n";
} 