/* ---------- Prim's Algorithm Using Adjacency Matrix ---------- */
#include <bits/stdc++.h>

// 5 7
// 0 1 4
// 0 2 8
// 1 2 2
// 1 3 6
// 2 3 3
// 2 4 9
// 3 4 5
// 4, 3, 2, 1, 0

// 6 11
// 1 3 1
// 0 1 2
// 0 3 3
// 0 2 4
// 4 5 5
// 2 3 6
// 3 5 7
// 2 1 8
// 2 4 9
// 2 5 10
// 3 4 11


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
    for(int j = 0;j < v - 1;j++){
        int minWeight = INT_MAX, ver = -1;
        for(int i = 0;i < v;i++){
            if(!visited[i] && minWeight > weights[i]){
                minWeight = weights[i];
                ver = i;
            }
        }
        // if(ver == -1) break;
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
    cout << "The Mst Is : \n";
    for(int i = 1;i < v;i++) cout << parents[i] << " " << i << " " << weights[i] << "\n";
}