#include <iostream>
#include <string>

using namespace std;

int cnt = 0;

void swap(string s, int i, int j){
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
    cout << s << "\n";
}

string s;
string temp;
int cnt = 0;

void printAllPoss(string p){
    do{
        cout << p << "\n";
        
        cnt++;
    } while(p != temp);
}

int main(){
    cin >> s;
    temp = s;
    printAllPoss(s);
    cout << cnt << " Strings\n";
}