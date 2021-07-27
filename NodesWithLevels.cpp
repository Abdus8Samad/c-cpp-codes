#include <iostream>
#include <vector>
#include <queue>

// 7 8
// 0 1
// 0 2
// 1 3
// 1 5
// 1 4
// 2 6
// 6 7

using namespace std;

void printNodesWithLevels(vector< vector<int> > edges, int v){
    queue<int> q;
    bool* visited = new bool[v];
    for(int i=0;i<v;i++) visited[i] = false;
    visited[0] = true;
    q.push(0);
    q.push(0);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        int lvl = q.front();
        q.pop();
        cout << t << ": " << lvl << "\n";
        for(int i=0;i<edges[t].size();i++){
            int ch = edges[t][i];
            if(visited[ch]) continue;
            visited[ch] = true;
            q.push(ch);
            q.push(lvl + 1);
        }
    }
    delete[] visited;
}

int main(){
    int e, v;
    cin >> e >> v;
    vector< vector<int> > edges(v);
    for(int i=0;i<e;i++){
        int l, r;
        cin >> l >> r;
        edges[l].push_back(r);
        edges[r].push_back(l);
    }
    printNodesWithLevels(edges, v);
}