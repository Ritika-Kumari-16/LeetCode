class Solution {
public:
int tabu(vector<int>&arr,int x){
        int n=arr.size();
        //  vector<vector<int>>dp(n,vector<int>(x+1,0));
        vector<int>prev(x+1,0);
        vector<int>curr(x+1,0);
        if(arr[0]==0) prev[0]=2;
        else prev[0]=1;
        if(arr[0]!=0&&arr[0]<=x)prev[arr[0]]=1;
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=x;sum++){
                int notTake=prev[sum];
                int take=0;
                if(arr[ind]<=sum) take=prev[sum-arr[ind]];
                
                
                curr[sum]=(take+notTake);
            }
            prev=curr;
        }
        return prev[x];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        //Approach -> Memoization
        int tosum=0;
        for(int i=0;i<n;i++){
            tosum+=arr[i];
        }
        if(tosum-d<0||(tosum-d)%2)return 0;
        int x=(tosum-d)/2;
        // vector<vector<int>>dp(n,vector<int>(x+1,-1));
        // return solve(n-1,d,arr,x,dp);
        
        
        //Approach Tabulation
        return tabu(arr,x);
       
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};