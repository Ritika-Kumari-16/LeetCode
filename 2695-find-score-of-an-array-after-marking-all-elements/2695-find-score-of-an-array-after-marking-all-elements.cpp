class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        vector<int>visited(nums.size(),0);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;

        for (int i=0;i<nums.size();i++){
            minheap.push({nums[i],i});
        }
        while(!minheap.empty()){
            long long minval=minheap.top().first;
            int idx=minheap.top().second;
            minheap.pop();
            if(visited[idx]==0){
                score+=nums[idx];
                visited[idx]=1;
                if(idx>0){
                    visited[idx-1]=1;
                }
                if(idx<nums.size()-1){
                    visited[idx+1]=1;
                }
            }
        }
        
        return score;
    }
};