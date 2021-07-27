#include <iostream>
#include <vector>
#include <climits>
#include "disjoinedSet.h"

using namespace std;

// vector<int>* boruvkas(vector< vector<int> >* edges, int v, int e){
//     vector< vector<int> > components;
//     vector<int>* mst = new vector<int>[v];
//     for(int i=0;i<v;i++){
//         vector< pair<int, int> > temp;
//         for(int j=0;j<edges[v].size();j++){
//             temp.push_back(make_pair(edges[i][j][0], 0));
//         }
//         vector<int> tmp;
//         tmp.push_back(i);
//         components.push_back(tmp);
//     }
//     int start = 0;
//     while(components[0].size() != v){
//         int mn = INT_MAX,l,r;
//         for(int i=start;i<components[0].size();i++){
//             for(int j=0;j<edges[i].size();j++){
//                 if(edges[i][j][0] == 1) continue;
//                 if(edges[i][j][1] < mn){
//                     mn = edges[i][j][1];
//                     r = edges[i][j][0];
//                     l = i;
//                 }
//             }
//         }
//     }
//     return mst;
// }

int main(){
    // int v, e;
    // cin >> v >> e;
    // vector< vector<int> >* edges = new vector< vector<int> >[v];
    // for(int i=0;i<e;i++){
    //     int l, r, w;
    //     cin >> l >> r >> w;
    //     vector<int> temp;
    //     temp.push_back(r);
    //     temp.push_back(w);
    //     edges[l].push_back(temp);
    //     temp.clear();
    //     temp.push_back(l);
    //     temp.push_back(w);
    //     edges[r].push_back(temp);
    // }
    // delete[] edges;
    // boruvkas(edges, v, e);
    disjoinedSet* d = new disjoinedSet(5);
    d->Union(0, 2);
    d->Union(4, 2);
    d->Union(3, 1);
    if (d->find(4) == d->find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
    if (d->find(1) == d->find(0))
        cout << "Yes\n";
    else
        cout << "No\n";
}