#include <bits/stdc++.h>

using namespace std;

vector<string> ret;
int k;
string temp = "";
unordered_set<string> path;
string us(int n, int i){
    string s;
    s += n + '0';
    s += i + '0';
    return s;
}
void helper(vector<vector<int>> &m, int n, int i){
    if(n == k || i == k || n < 0 || i < 0 || path.count(us(n, i))) return;
    if(m[n][i] == 0) return;
    if(i == k - 1 && n == i){
        ret.push_back(temp);
        return;
    }
    path.insert(us(n, i));
    temp += 'D';
    helper(m, n + 1, i);
    temp = temp.substr(0, temp.size() - 1);
    temp += 'L';
    helper(m, n, i - 1);
    temp = temp.substr(0, temp.size() - 1);
    temp += 'R';
    helper(m, n, i + 1);
    temp = temp.substr(0, temp.size() - 1);
    temp += 'U';
    helper(m, n - 1, i);
    temp = temp.substr(0, temp.size() - 1);
    path.erase(us(n, i));
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[n - 1][n - 1] == 0) return ret;
    k = n;
    helper(m, 0, 0);
    return ret;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> m;
    for(int i=0;i<n;i++){
        vector<int> row;
        for(int j=0;j<n;j++){
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        m.push_back(row);
    }
    ret = findPath(m, n);
    for(int i=0;i<ret.size();i++){
        cout << ret[i] << "\n";
    }
}

// 4
// 1 0 0 0
// 1 1 0 1
// 1 1 0 0
// 0 1 1 1