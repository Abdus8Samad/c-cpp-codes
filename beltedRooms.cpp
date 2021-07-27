#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, i = 0, off = 0, c = 0, an = 0, rab = 0;
        cin >> n;
        string s;
        cin >> s;
        for(;i < n;i++){
            if(s[i] == '-') off++;
            else if(s[i] == '>') c++;
            else an++;
        }
        i = 0;
        int a = n - 1, b = 0, cPos = c + off, acPos = an + off;
        for(;i < n;i++){
            if(s[a] == '-' || s[b] == '-') rab++;
            else if(s[b] == '>' && cPos == n) rab++;
            else if(s[a] == '<' && acPos == n) rab++;
            a == n - 1 ? a = 0 : a++;
            b == n - 1 ? b = 0 : b++;
        }
        cout << rab << "\n";
    }
}