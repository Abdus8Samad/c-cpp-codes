// 8 13
// 0 1 4
// 5 1 3
// 0 2 4
// 2 5 -2
// 3 0 3
// 3 2 2
// 2 4 4
// 4 3 1
// 5 4 -2
// 4 6 -2
// 7 4 -1
// 6 7 -1
// 6 5 4
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class edge{
public:
    int l, r, w;
    edge(int l, int r, int w){
        this->l = l;
        this->r = r;
        this->w = w;
    }
};

int main(){
    int v, e;
    cin >> v >> e;
    vector<edge> edges;
    vector<int> dist;
    for(int i=0;i<v;i++) dist.push_back(INT_MAX);
    dist[0] = 0;
    for(int i=0;i<e;i++){
        int l, r, w;
        cin >> l >> r >> w;
        edge temp(l, r, w);
        edges.push_back(temp);
    }
    for(int i=1;i<v;i++){
        for(int i=0;i<e;i++){
            int l = edges[i].l;
            int r = edges[i].r;
            int w = edges[i].w;
            if(dist[l] != INT_MAX && dist[r] > dist[l] + w) dist[r] = dist[l] + w;
        }
    }
    int a = 0;
    for(int i=0;i<e;i++){
        int l = edges[i].l;
        int r = edges[i].r;
        int w = edges[i].w;
        if(dist[l] != INT_MAX && dist[r] > dist[l] + w){
            a = 1;
            break;
        }
    }
    cout << (a ? "YES" : "NO") << "\n";
}