class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>ans;
        deque<int>q;
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[q.back()]<=nums[i]) q.pop_back();
            q.push_back(i);
            while(i-q.front()>=k) q.pop_front();
            if((i+1)-k>=0){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};