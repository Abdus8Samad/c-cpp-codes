#include <bits/stdc++.h>

// Prim's Algorithm Using Adjacency Matrix

// 5 7
// 0 1 4
// 0 2 8
// 1 2 2
// 1 3 6
// 2 3 3
// 2 4 9
// 3 4 5

using namespace std;

int main(){
    int v, e;
    cin >> v >> e;
    vector<int> visited(v, 0);
    vector<int> weights(v, INT_MAX);
    vector<int> parents(v, 0);
    vector<vector<int>> adj(v, vector<int>(v, 0));
    parents[0] = -1;
    weights[0] = 0;
    while(e--){
        int l, r, w;
        cin >> l >> r >> w;
        adj[l][r] = w;
        adj[r][l] = w;
    }
    while(true){
        int minWeight = INT_MAX, ver = -1;
        for(int i = 0;i < v;i++){
            if(!visited[i] && minWeight > weights[i]){
                minWeight = weights[i];
                ver = i;
            }
        }
        if(ver == -1) break;
        visited[ver] = 1;
        for(int i = 0;i < v;i++){
            if(adj[ver][i] && !visited[i]){
                if(adj[ver][i] < weights[i]){
                    weights[i] = adj[ver][i];
                    parents[i] = ver;
                }
            }
        }
    }
    int p = v - 1;
    while(p != -1){
        cout << p << ", ";
        p = parents[p];
    }
}