class disjoinedSet{
    int* parents;
    int* ranks;
public:
    disjoinedSet(int n){
        parents = new int[n];
        ranks = new int[n];
        for(int i=0;i<n;i++){
            parents[i] = i;
            ranks[i] = 1;
        }
    }
    int find(int x){
        if(parents[x] == x) return x;
        int rep = find(parents[x]);
        parents[x] = rep;
        return rep;
    }
    void Union(int x, int y){
        int xRep = find(x), yRep = find(y), xRank = ranks[x], yRank = ranks[y];
        if(xRep == yRep) return;
        if(xRank > yRank) parents[yRep] = xRep;
        else if(xRank < yRank) parents[xRep] = yRep;
        else {
            parents[xRep] = yRep;
            ranks[yRep] = ranks[yRep] + 1;
        }
    }
};
