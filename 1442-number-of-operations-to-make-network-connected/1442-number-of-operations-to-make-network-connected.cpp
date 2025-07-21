class DisjointSet {
public:
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int conntotal=0;
        int num=0;
        int notconntotal=0;
        DisjointSet ds(n);
        for(auto &it: connections){
            int u= it[0];
            int v=it[1];
            if(ds.find(u,v)){
                conntotal++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        for(int i=0;i<n;i++){
            if(ds.findparent(i)==i){
                notconntotal++;
            }
        }
        if(notconntotal-1<=conntotal) return notconntotal-1;
        return  -1;
        
    }
};