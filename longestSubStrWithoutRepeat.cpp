#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string S) {
    if(S.length() == 1 || S.length() == 0) return S.length();
    int maxLength = 1, l=0, r=0;
    int m[255];
    for(int i=0;i<255;i++) m[i] = -1;
    for(int i=0;i<S.length();i++){
        if(m[S[i] - 0] != -1 && m[S[i] - 0] >= l) l = m[S[i] - 0] + 1;
        m[S[i] - 0] = i;
        r = i;
        if(r - l + 1 > maxLength) maxLength = r - l + 1;
    }
    return maxLength;
}

int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << "\n";
}