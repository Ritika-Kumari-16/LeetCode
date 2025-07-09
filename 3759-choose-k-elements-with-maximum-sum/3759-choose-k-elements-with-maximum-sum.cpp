class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {
        vector<pair<int,pair<int, int>>> nums;
        for (int i = 0; i < nums1.size(); i++) {
            nums.push_back({nums1[i], {i,nums2[i]}});
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        vector<long long> result(nums1.size(), 0);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            if(i>0 && nums[i].first==nums[i-1].first){
                int idx= nums[i-1].second.first;
                long long ans= result[idx];
                result[nums[i].second.first]=ans;
            }
            else{
                int idx= nums[i].second.first;
                result[idx]=sum;
            }
            sum+=nums[i].second.second;
            pq.push(nums[i].second.second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
 
        }
        return result;
    }
};