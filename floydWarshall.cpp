/* ---------- Floyd Warshall ---------- */
/* Can be used in directed graphs and if weights are positive then for undirected graph as well */
/* Fails to provide correct ans for graphs with negative weight cycles */
/* Distance to self node is negative in case of negative cycles so can detect them in this way*/
#include <iostream>
#include <vector>

// 4 4
// 0 3 10
// 0 1 5
// 1 2 3
// 2 1 1

// Shortest Distances for every pairs are:
// 0 0 0
// 0 1 5
// 0 2 8
// 0 3 10
// 1 0 2147483647
// 1 1 0
// 1 2 3
// 1 3 2147483647
// 2 0 2147483647
// 2 1 1
// 2 2 0
// 2 3 2147483647
// 3 0 2147483647
// 3 1 2147483647
// 3 2 2147483647
// 3 3 0

using namespace std;

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v, vector<int> (v, INT_MAX));
    for(int i = 0;i < v;i++) adj[i][i] = 0;
    while(e--){
        int l, r, w;
        cin >> l >> r >> w;
        adj[l][r] = w;
    }
    for(int k = 0;k < v;k++){
        for(int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                if(adj[i][j] > adj[i][k] + adj[k][j] && adj[i][k] != INT_MAX && adj[k][j] != INT_MAX){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    cout << "Shortest Distances for every pairs are: \n";
    int a = 0;
    for(int i = 0;i < v;i++){
        for(int j = 0;j < v;j++){
            if(i == j && adj[i][j] < 0) a = 1;
            cout << i << " " << j << " " << adj[i][j] << "\n";
        }
    }
    if(a) cout << "Negative Cycles Present\n";
    else cout << "No Negative Cycles Present\n";
}