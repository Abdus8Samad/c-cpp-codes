#include <iostream>
#include <stack>

// time -> O(n2)
// space -> O(1) (excluding recursive stack)

using namespace std;

void pushAtBottom(stack<int>& s, int t){
    if(s.size() == 0) s.push(t);
    else {
        int l = s.top();
        s.pop();
        pushAtBottom(s, t);
        s.push(l);
    } 
}

void reverseStack(stack<int>& s){
    if(s.size() > 0){
        int t = s.top();
        s.pop();
        reverseStack(s);
        pushAtBottom(s, t);
    }
}

int main(){
    int n;
    cin >> n;
    stack<int> s;
    while(n--){
        int temp;
        cin >> temp;
        s.push(temp);
    }
    reverseStack(s);
    while(!s.empty()){
        cout << s.top() << ", ";
        s.pop();
    }
}