class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=queries.size();
        for(int it=0;it<n;it++){
            int start= queries[it][0];
            int end= queries[it][1];
            int result =0;
                for(int i=start;i<=end;i++){
                    result=result^arr[i];}
                    ans.push_back(result);
            }
        return ans;
    }
};