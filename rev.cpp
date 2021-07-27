#include <iostream>
#include <stack>

using namespace std;

char* reverse(char *S, int len){
    char* arr = new char[len];
    arr[len] = '\0';
    stack<char> s;
    int i = len - 1;
    while(len--) s.push(S[i - len]);
    i = 0;
    while(!s.empty()){
        char c = s.top();
        s.pop();
        arr[i] = c;
        i++;
    }
    return arr;
}

int main() {
    int len;
    cin >> len;
    char* arr = new char[len];
    cin >> arr;
    cout << reverse(arr, len) << "\n";
    return 0;
}