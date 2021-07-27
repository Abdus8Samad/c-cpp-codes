#include <iostream>
#include <vector>

using namespace std;

void func(int n, vector<string>& res){
    if(n == 0) return;
    if(n == 1){
        res.push_back("0");
        res.push_back("1");
        return;
    }
    func(n - 1, res);
    int i = 0, k = res.size();
    for(;i < k;i++){
        if(res[i][res[i].length() - 1] == '0') res[i] += "1";
        else {
            res.push_back(res[i] + "0");
            res[i] += "1";
        }
    }
}

int alternateFunc(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return n + 1;
    int a = 2, b = 3, c = 0;
    for(int i=3;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    vector<string> res;
    func(n, res);
    cout << res.size() << " Substrings\n";
    cout << alternateFunc(n) << " Substrings\n";
    // for(auto i : res) cout << i << "\n";
}