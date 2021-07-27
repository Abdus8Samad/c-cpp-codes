#include <iostream>
#include <stack>

using namespace std;

int precedence(char a){
    if(a == '^') return 2;
    if(a == '*'|| a == '/') return 1;
    if(a == '+'|| a == '-') return 0;
}
string infixToPostfix(string s){
    string post = "";
    stack<char> op;
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if(c == '('){
            string tmp = "";
            i++;
            if(i == s.size()) break;
            char c = s[i];
            int cnt = 0;
            while(cnt || c != ')'){
                if(c == '(') cnt++;
                else if(c == ')') cnt--;
                tmp += c;
                i++;
                if(i == s.size()) break;
                c = s[i];
            }
            post += infixToPostfix(tmp);
        }
        else if(c == '-' || c == '+' || c == '*' || c == '/' || c == '^'){
            while(!op.empty() && precedence(s[i]) <= precedence(op.top())){
                post += op.top();
                op.pop();
            }
            op.push(s[i]);
        } else post += s[i];
    }
    while(!op.empty()){
        post += op.top();
        op.pop();
    }
    return post;
}

int main(){
    string s;
    cin >> s;
    cout << infixToPostfix(s) << "\n";
}