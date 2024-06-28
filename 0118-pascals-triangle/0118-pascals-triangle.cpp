vector<int>funncr(int r){
    vector<int>temp;
    long long ans=1;
    temp.push_back(ans);
    for(int i=1;i<r;i++){
        ans=ans*(r-i);
        ans=ans/i;
        temp.push_back(ans);
    }
    return temp;
}
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(funncr(i));
        }
        return ans;
        
    }
};