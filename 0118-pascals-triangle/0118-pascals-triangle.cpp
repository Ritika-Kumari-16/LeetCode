class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows; i++){
            vector<int>temp;
            temp.push_back(1);
            int val=1;
            for(int j=1;j<i;j++){
                val=val*(i-j);
                val=val/j;
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};