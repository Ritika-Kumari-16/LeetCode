vector<int>elesofrow(int r,vector<int>&ans){
    long long ans2=1;
    ans.push_back(ans2);
    for(int i=1;i<r;i++){
        ans2=ans2*(r-i);
        ans2=ans2/i;
        ans.push_back(ans2);
    }
    return ans;
}
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        elesofrow(rowIndex+1,ans);
        return ans;
    }
};