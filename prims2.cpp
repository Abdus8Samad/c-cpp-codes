#include <bits/stdc++.h>

// Prim's Algorithm Using Adjacency List and Priority Queue

// 5 7
// 0 1 4
// 0 2 8
// 1 2 2
// 1 3 6
// 2 3 3
// 2 4 9
// 3 4 5

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
    vector<vector<vector<int>>> adj(v);
    while(e--){
        int l, r, w;
        cin >> l >> r >> w;
        vector<int> temp = {r, w};
        adj[l].push_back(temp);
        temp[0] = l;
        adj[r].push_back(temp);
    }
    vector<int> visited(v, 0);
    vector<int> parents(v, 0);
    vector<int> weights(v, INT_MAX);
    weights[0] = 0;
    parents[0] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    for(int j = 0;j < v;j++){
        pair<int, int> p = pq.top();
        pq.pop();
        visited[p.second] = 1;
        for(int i = 0;i < adj[p.second].size();i++){
            int w = adj[p.second][i][1], child = adj[p.second][i][0];
            if(!visited[child] && w < weights[child]){
                weights[child] = w;
                parents[child] = p.second;
                pq.push({w, child});
            }
        }
    }
    cout << "The Mst Is : \n";
    for(int i = 1;i < v;i++) cout << parents[i] << " " << i << " " << weights[i] << "\n";
}