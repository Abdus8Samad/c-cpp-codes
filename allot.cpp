#include <iostream>
using namespace std;

const int totalstudent = 14;

int maxes[3] = {5, 5, 4};

struct datatotal{
    int rollNo;
    char choice1;
    char choice2;
    char choice3;
    char finalallotted;
} s[totalstudent];

int main(){
    cout << "\n\n Paste the Data: \n\n";    
    for (int i = 0; i < totalstudent; i++){
        cin >> s[i].rollNo >> s[i].choice1 >> s[i].choice2 >> s[i].choice3;        
    }
    for(int i = 0;i < totalstudent; i++){
        int a = s[i].choice1;
        int b = s[i].choice2;
        int c = s[i].choice3;
        if(maxes[a - 65]){
            s[i].finalallotted = a;
            maxes[a - 65]--;
        } else if(maxes[b - 65]){
            s[i].finalallotted = b;
            maxes[b - 65]--;
        } else {
            s[i].finalallotted = c;
            maxes[c - 65]--;
        }
        cout << s[i].finalallotted << "\n";
    }
}