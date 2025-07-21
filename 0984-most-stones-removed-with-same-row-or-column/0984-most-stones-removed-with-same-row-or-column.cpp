class DisjointSet {
    vector<int>parent;
    vector<int>rank;
    vector<int>size;
public:
    DisjointSet(int n) {
     parent.resize(n+1,0);
     rank.resize(n+1,0);
     size.resize(n+1,1);
     for(int i=0;i<=n;i++){
        parent[i]=i;
     }
    }

    bool find(int u, int v) {
        return findparent(u)==findparent(v);
    }
    int findparent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findparent(parent[u]);
    }

    void unionByRank(int u, int v) {
        int upu=findparent(u);
        int upv=findparent(v);
        if(upu==upv) return ;
        if(rank[upu]<rank[upv]){
            parent[upu]=upv;
        }
        else if(rank[upu]>rank[upv]){
            parent[upv]=upu;
        }
        else{
            parent[upv]=upu;
            rank[upu]++;
        }
     
    }

    void unionBySize(int u, int v) {
        int upu=findparent(u);
        int upv=findparent(v);
        if(upu==upv) return ;
        if(size[upu]<size[upv]){
            parent[upu]=upv;
            size[upv]+=size[upu];
        }
        else if(size[upu]>size[upv]){
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        else {
            parent[upv]=upu;
            size[upu]+=size[upv];
        }
        
       
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto &it: stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrow+maxcol+1);
        unordered_map<int,int>mpp;
        for(auto it: stones){
            int row=it[0];
            int col=it[1];
            ds.unionBySize(row,maxrow+1+col);
            mpp[row]=1;
            mpp[maxrow+1+col]=1;
        }
        int count=0;
        for(auto it: mpp){
            if(ds.findparent(it.first)==it.first){
                count++;
            }
        }
        return n-count;
    }
};