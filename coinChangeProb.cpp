#include <iostream>
#include <vector>

using namespace std;

int coinChanges(vector<int> coins, int n, int s, int e){
    if(n == 0) return 1;
    if(s > e || n < 0) return 0;
    int ret = coinChanges(coins, n - coins[s], s, e) + coinChanges(coins, n, s + 1, e);
    return ret;
}

int main(){
    int n, l;
    cin >> n >> l;
    vector<int> coins;
    while(l--){
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    cout << coinChanges(coins, n, 0, coins.size() - 1) << "\n";
}