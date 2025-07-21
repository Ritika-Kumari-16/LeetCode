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
    int largestIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n+1);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,0,0,1};
                int dc[]={0,-1,1,0};
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]){
                        int node= row*n+col;
                        int nnode=nrow*n+ncol;
                        ds.unionBySize(node,nnode);
                    }
                }
            }
        }
        int maxsize=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,0,0,1};
                int dc[]={0,-1,1,0};
                unordered_set<int>st;
                for(int i=0;i<4;i++){
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]){
                        int nnode=nrow*n+ncol;
                        st.insert(ds.findparent(nnode));
                    }
                }
                int sizetotal=0;
                for(auto it:st){
                    sizetotal+=ds.size[it];
                }
                maxsize=max(maxsize,sizetotal+1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxsize=max(maxsize,ds.size[ds.findparent(i*n+j)]);
            }
        }
        return maxsize;
    }
};