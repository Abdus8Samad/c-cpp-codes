#include <iostream>
#include <string>
#include <vector>

using namespace std;

string maxString;
// void swap(char* a, char* b){
//     char c = *b;
//     *b = *a;
//     *a = c;
// }
void func(string str, int k, int i){
    if(k == 0 || i >= str.length()){
        if(str > maxString) maxString = str;
        return;
    }
    int maxIndex = i;
    vector<int> maxes;
    for(int j=i + 1;j < str.length();j++){
        if(str[j] >= str[maxIndex] && str[j] != str[i]){
            maxIndex = j;
            maxes.push_back(maxIndex);
        }
    } 
    if(maxes.size() > 0){
        for(int j=0;j<maxes.size();j++){
            string strNew = str;
            swap(strNew[i], strNew[maxes[j]]);
            func(strNew, k - 1, i + 1);
        }
    } else {
        func(str, k, i + 1);
    }
}
string findMaximumNum(string str, int k){
    maxString = str;
    func(str, k, 0);
    return maxString;
}

int main(){
    int k;
    string s;
    cin >> s >> k;
    cout << findMaximumNum(s, k) << "\n";
}

// Input:

// 4
// 61892795431

// Its Correct output is:

// 99876215431

// And Your Code's output is:

// 99876125431

// 4551711527 3
