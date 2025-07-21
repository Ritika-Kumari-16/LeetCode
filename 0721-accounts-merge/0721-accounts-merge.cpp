
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        DisjointSet ds(n);
        unordered_map<string ,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]=i;
                }
                else{
                    ds.unionBySize(mpp[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>>emailsstored(n);
        for(auto it:mpp){
            int pnode= ds.findparent(it.second);
            emailsstored[pnode].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(emailsstored[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            vector<string>t(emailsstored[i].begin(),emailsstored[i].end());
            sort(t.begin(),t.end());
            for(auto s :t){
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};