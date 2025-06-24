class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n =  nums.size();
        if(n==0) return 0;
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxlen=1;
        for(auto &el :st){
            if(st.find(el-1)==st.end()){
                int count=1;
                int x=el+1;
                while(st.find(x)!=st.end()){
                    count++;
                    x++;
                    maxlen=max(maxlen,count);

                }
            }
        }
        return maxlen;
    }
};