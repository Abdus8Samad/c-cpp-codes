#include <iostream>
#include <vector>

using namespace std;

vector<int> dfsArr;

bool dfs(vector< vector<int> > edges, int v, int s, bool* visited, bool* reStack){
    visited[s] = true;
    for(int i=0;i<edges[s].size();i++){
        reStack[s] = true;
        if(reStack[edges[s][i]]) return true;
        if(visited[edges[s][i]]) continue;
        if(dfs(edges, v, edges[s][i], visited, reStack)) return true;
    }
    reStack[s] = false;
    return false;
}

bool hasCycle(vector< vector<int> > edges, int v){
    bool* visited = new bool[v];
    bool* reStack = new bool[v];
    for(int i=0;i<v;i++){
        visited[i] = false;
        reStack[i] = false;
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(edges, v, i, visited, reStack)){
                delete[] visited;
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector< vector<int> > edges(v);
    for(int i=0;i<e;i++){
        int l, r;
        cin >> l >> r;
        edges[l].push_back(r);
    }
    cout << hasCycle(edges, v) << "\n";
}