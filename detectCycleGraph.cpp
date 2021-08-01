#include <iostream>
#include <vector>

using namespace std;

bool helper(vector<vector<int>> adj, vector<int>& visited, vector<int>& recStack, int s, int parent){
    recStack[s] = 1;
    visited[s] = 1;
    for(int i = 0;i < adj.size();i++){
        // i != parent for unDirectedGraphs
        if(adj[s][i] && i != parent){
            if((recStack[i] && visited[i]) || helper(adj, visited, recStack, i, s)) return true;
        }
    }
    recStack[s] = 0;
    return false;
}

bool isCycle(vector<vector<int>> adj){
    int v = adj.size();
    vector<int> visited(v, 0);
    vector<int> recStack(v, 0);
    for(int i = 0;i < v;i++){
        if(!visited[i]){
            if(helper(adj, visited, recStack, i, -1)) return true;
        }
    }
    return false;
}

int main(){
    int v, e;
    cin >> v >> e;
    vector<vector<int>> adj(v, vector<int>(v, 0));
    while(e--){
        int l, r;
        cin >> l >> r;
        adj[l][r] = 1;
        adj[r][l] = 1;
    }
    if(isCycle(adj)) cout << "Cycle is present\n";
    else cout << "No cycle is present\n";
}