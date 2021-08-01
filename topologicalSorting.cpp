/* ---------- Topological Sorting ---------- */
/* Only for Directed Acyclic Graph which is logical */
#include <iostream>
#include <vector>

using namespace std;

void helper(int node, vector<vector<int>> adj, vector<int>& visited, vector<int>& ret){
    visited[node] = 1;
    for(int i = 0;i < adj[node].size();i++){
        if(adj[node][i]){
            if(visited[adj[node][i]]) continue;
            helper(adj[node][i], adj, visited, ret);
        }
    }
    ret.push_back(node);
}

vector<int> oneTopologicalSorting(int v, vector<vector<int>> adj){
    vector<int> visited(v, 0);
    vector<int> ret;
    for(int i = 0;i < v;i++){
        if(!visited[i]) helper(i, adj, visited, ret);
    }
    for(int i = 0;i < ret.size() / 2;i++){
        int temp = ret[i];
        ret[i] = ret[ret.size() - i - 1];
        ret[ret.size() - i - 1] = temp;
    }
    return ret;
}

// bool isConnected(int a, int b, vector<vector<int>> adj){
//     for(int i=0;i<adj[a].size();i++) if(adj[a][i] == b) return true;
//     for(int i=0;i<adj[b].size();i++) if(adj[b][i] == a) return true;
//     return false;
// }

vector<vector<int>> ret;
vector<vector<int>> allTopologicalSortings(int v, vector<vector<int>> adj, vector<int>& visited){
    
}

int main(){
    int v, e;
    cin >> v >> e;
    // adjacency list
    vector<vector<int>> adj(v, vector<int>(0, 0));
    while(e--){
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
    }
    vector<int> tS = oneTopologicalSorting(v, adj);
    cout << "One of the topological sorting : ";
    for(auto i : tS) cout << i << " ";
    cout << "\n";
    cout << "All of the topological sortings : \n";
    vector<int> visited(v, 0);
    vector<vector<int>> allTs = allTopologicalSortings(v, adj, visited);
    for(auto srt : allTs){
        for(auto i : srt){
            cout << i << " ";
        }
        cout << "\n";
    }
}

// Sample Input
// 6 6
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1
// 5 2
// Output
// 5 4 2 3 1 0