class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badpairs=0;
        long long pairs=0;
        int n= nums.size();
        vector<int>num(n);
        for(int i=0;i<n;i++){
            num[i]=nums[i]-i;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int totalele=i;
            int seenbefore=mp[num[i]];
            pairs=totalele-seenbefore;
            badpairs+=pairs;
            mp[num[i]]++;
        }
        return badpairs;
    }
};