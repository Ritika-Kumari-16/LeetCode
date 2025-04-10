class Solution {
public:
typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        vector<vector<int>>vec(n);
        vector<ll>ans(n,0);
        for(int i=0;i<n;i++){
            vec[i]={nums1[i],i,nums2[i]};
        }
        sort(vec.begin(),vec.end());
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll sum=0;
        for(int i=0;i<n;i++){
            if(i>0 && vec[i-1][0]==vec[i][0]){
                ll sum1= ans[vec[i-1][1]];
                ans[vec[i][1]]=sum1;
            }
            else{
                ans[vec[i][1]]=sum;
            }
            sum+=vec[i][2];
            pq.push(vec[i][2]);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};