#include <iostream>
#include <vector>
#include <set>

// 8 7
// 0 2
// 0 1
// 1 3
// 4 1
// 6 4
// 5 6
// 5 2
// 6 0

// 5 5
// 0 3
// 0 2
// 3 4
// 1 0
// 2 1

using namespace std;

void dfs(vector< vector<int> > edges, int s, bool* visited){
    visited[s] = true;
    for(int i=0;i<edges[s].size();i++){
        dfs(edges, edges[s][i], visited);
    }
}

int motherVertex(vector< vector<int> > edges, int v){
    int ret = -1;
    bool* visited = new bool[v];
    for(int i=0;i<v;i++) visited[i] = false;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            ret = i;
            dfs(edges, i, visited);
        }
    }
    cout << ret << "\n";
    for(int i=0;i<v;i++) visited[i] = false;
    dfs(edges, ret, visited);
    for(int i=0;i<v;i++) if(!visited[i]) return -1;
    delete[] visited;
    return ret;
}

int main(){
    int e, v;
    cin >> e >> v;
    vector< vector<int> > edges(v);
    for(int i=0;i<e;i++){
        int l, r;
        cin >> l >> r;
        edges[l].push_back(r);
    }
    for(int i=0;i<v;i++){
        cout << i << ": ";
        for(int j=0;j<edges[i].size();j++){
            cout << edges[i].at(j) << ", ";
        }
        cout << "\n";
    }
    cout << motherVertex(edges, v);
}