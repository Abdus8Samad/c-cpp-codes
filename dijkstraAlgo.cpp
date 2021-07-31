// Dijkstra Algorithm

#include <bits/stdc++.h>

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
    vector<int> weights(v, INT_MAX);
    vector<int> visited(v, 0);
    weights[0] = 0;
    // // For a single destination
    // int dest = 1;
    // while(true){
    //     int minWeight = INT_MAX, vert = -1;
    //     for(int i = 0;i < v;i++){
    //         if(!visited[i] && weights[i] < minWeight){
    //             minWeight = weights[i];
    //             vert = i;
    //         }
    //     }
    //     visited[vert] = 1;
    //     if(vert == dest) break;
    //     for(int i = 0;i < adj[vert].size();i++){
    //         vector<int> vertex = adj[vert][i];
    //         int w = vertex[1], child = vertex[0];
    //         if(w + weights[vert] < weights[child]){
    //             weights[child] = w + weights[vert];
    //         }
    //     }
    // }
    // cout << weights[dest] << "\n";
    for(int i = 0;i < v;i++){
        int minWeight = INT_MAX, vert = -1;
        for(int i = 0;i < v;i++){
            if(!visited[i] && weights[i] < minWeight){
                minWeight = weights[i];
                vert = i;
            }
        }
        visited[vert] = 1;
        for(int i = 0;i < adj[vert].size();i++){
            vector<int> vertex = adj[vert][i];
            int w = vertex[1], child = vertex[0];
            if(w + weights[vert] < weights[child]){
                weights[child] = w + weights[vert];
            }
        }
    }
    for(int i = 0;i < v;i++) cout << weights[i] << ", ";
}