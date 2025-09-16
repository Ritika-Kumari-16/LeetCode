class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n= nums.size();
        vector<int>ans;
        for(auto &num : nums){
              while(!ans.empty()){
                int prev=ans.back();
                int cur=num;
                int GCD=gcd(prev,cur);
                if(GCD==1) break;
                int LCM= prev/GCD * cur;
                ans.pop_back();
                num=LCM;
            }
            ans.push_back(num);
        }
        return ans;
    }
};