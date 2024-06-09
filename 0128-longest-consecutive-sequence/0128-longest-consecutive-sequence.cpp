class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int count=0;
        int x;
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                count=1;
                x=it;
            }
            while(st.find(x+1)!=st.end()){
                x=x+1;
                count++;
            }
            maxlen=max(maxlen,count);
        }
        return maxlen;
        
    }
};