// aabaabbbab
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int a = 0, b = 0,k,bm = 0,bmi;
    cin >> s;
    cin >> k;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'a') a++;
        else a--;
    }
    for(int i = 0;i<s.length();i++){
        if(s[i] == 'a'){
            (a >= 0) ? b++ : b--;
        } else {
            (a < 0) ? b++ : b--;
        }
        if(b >= bm){
            bm = b;
            bmi = i;
        }
    }
    
    int i = bmi;
    b = 0;
    cout << bm << "\n";
    cout << bmi << "\n";
    while(k){
        if(a >= 0){
            if(s[i] == 'b') k--;
        } else {
            if(s[i] == 'a') k--;
        }
        b++;
        if(i == 0) break;
        i--;
    }
    while((a >= 0) ? s[i] == 'a' : s[i] == 'b'){
        b++;
        if(i == 0) break;
        i--;
    }
    cout << b << "\n";
} 