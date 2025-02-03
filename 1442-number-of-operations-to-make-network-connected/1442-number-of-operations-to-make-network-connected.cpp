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
    void dounionSet( int u , int v){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extracables=0;
        DisjointSet ds(n);
        for (auto it: connections){
            int u= it[0];
            int v= it[1];
            if(ds.findpar(u)==ds.findpar(v)){
                extracables++;
            }
            else{
                ds.dounionSet(u,v);
            }
        }
        int cntforcom=0;
        for( int i=0;i<n;i++){
            if(ds.par[i]==i){
                cntforcom++;
            }
        }
        int ans= cntforcom-1;
        if(extracables>=ans) return ans;
        return -1;
        
    }
};