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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds (n);
        unordered_map<string,int>mailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail= accounts[i][j];
                if(mailnode.find(mail)==mailnode.end()){
                    mailnode[mail]=i;
                }
                else{
                    ds.dounionSet(i,mailnode[mail]);
                }

            }
        }
        vector<vector<string>>mergemail(n);
        for(auto it : mailnode){
            string mail = it.first;
            int node= ds.findpar(it.second);
            mergemail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergemail[i].size()==0) continue;
            sort(mergemail[i].begin(),mergemail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for( auto it: mergemail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};