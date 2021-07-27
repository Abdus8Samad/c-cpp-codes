#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > corr = {
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {0, 0, 1, 1, 0, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
};

int possPass(int n, int m, int l, vector<int> possNums){
    if(l == 0) return 1;
    int ans = 0;
    vector<int> newPossNums;
    for(int i=0;i<10;i++){
        int a = 0;
        if(l == 1) ans += possNums[i] && corr[m][i];
        else ans += possNums[i];
        for(int j=0;j<possNums.size();j++){
            int t = 0;
            if(l == 1) t = corr[m][i];
            a += corr[possNums[j]][i] + m;
        }
        if(a > 0){
            a = 1;
        }
        newPossNums.push_back(a);
    }
    cout << ans << "\n";
    return ans * possPass(n, m, l - 1, newPossNums);
}

// 1 2 3
// 4 5 6
// 7 8 9
//   0

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    cout << possPass(n, m, k - 2, corr[n]) << "\n";
}