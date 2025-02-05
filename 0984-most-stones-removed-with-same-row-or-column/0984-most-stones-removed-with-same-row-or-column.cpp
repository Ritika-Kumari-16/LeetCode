class DisjointSet{
    
public:
    vector<int>par,rank;
    DisjointSet ( int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int findpar(int node){
        if(par[node]==node){
            return node;
        }
        return par[node]=findpar(par[node]);
    }
    void unionSet( int u , int v){
        int upu=findpar(u);
        int upv=findpar(v);
        if(upu==upv) return ;
        if(rank[upu]<rank[upv]){
            par[upu]=upv;
        }
        else if(rank[upu]>rank[upv]){
            par[upv]=upu;
        }
        else{
            par[upu]=upv;
            rank[upv]++;
        }
    }

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int maxrow=0;
        int maxcol=0;
        for( auto& it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);

        }
        DisjointSet ds(maxrow+maxcol+2);
        unordered_set<int>visitednodes;
        for(auto it:stones){
            int nrow=it[0];
            int ncol=it[1]+maxrow+1;
            ds.unionSet(nrow,ncol);
            visitednodes.insert(nrow);
            visitednodes.insert(ncol);
        }
        int cnt=0;
        for(auto it: visitednodes){
            if(ds.findpar(it)==it){
                cnt++;
            }
        }
        return n-cnt;
        
    }
};