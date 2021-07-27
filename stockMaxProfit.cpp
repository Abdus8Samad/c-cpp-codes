#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > stockBuySell(vector<int> st, int n){
    vector< vector<int> > ret;
    int a = 0, b, pro = 0;
    for(int i=0;i<n;i++){
        if(st[i] < st[i + 1] && !a){
            b = i;
            a = 1;
        }
        if(st[i] > st[i + 1] && a){
            vector<int> temp;
            temp.push_back(b);
            temp.push_back(i);
            pro += st[i] - st[b];
            ret.push_back(temp);
            a = 0;
        }
    }
    if(a == 1 && st[n - 1] > st[b]){
        vector<int> temp;
        temp.push_back(b);
        temp.push_back(n - 1);
        pro += st[n - 1] - st[b];
        ret.push_back(temp);        
    }
    cout << pro << "\n";
    return ret;
}

int main(){
    vector<int> arr;
    int n, k;
    cin >> n;
    k = n;
    while(n--){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector< vector<int> > ans = stockBuySell(arr, k);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++) cout << ans[i][j] << ", ";
        cout << "\n";
    }
}