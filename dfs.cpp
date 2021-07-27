#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfsRec(int v, int si, bool* visited, vector<int> adj[], vector<int>& ret){
        ret.push_back(si);
        visited[si] = true;
        for(int i=0;i<adj[si].size();i++){
            if(visited[adj[si][i]]) continue;
            dfsRec(v, adj[si][i], visited, adj, ret);
        }
    }
	vector<int>dfsOfGraph(int v, vector<int> adj[]){
	    vector<int> ret;
	    bool* visited = new bool[v];
        for(int i=0;i<v;i++) visited[i] = false;
	    dfsRec(v, 0, visited, adj, ret);
        delete[] visited;	    
	    return ret;
	}
};
int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int v, e;
        cin >> v >> e;
        vector<int> adj[v];
        for(int i=0;i<e;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(v, adj);
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}