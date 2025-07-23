
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
     int n= nums.size()/3;
     int m= nums.size();
     vector<long long>leftmin(m,0);
     vector<long long>rightmax(m,0);
     priority_queue<int>maxheap;
     priority_queue<int,vector<int>,greater<>>minheap;
     long long sum=0;
     for(int i=0;i<2*n;i++){
        sum+=nums[i];
        maxheap.push(nums[i]);
        if(maxheap.size()>n){
            sum-=maxheap.top();
            maxheap.pop();
        }
        leftmin[i] = sum;
     }
     sum=0;
     for(int i=m-1;i>=n;i--){
        sum+=nums[i];
        minheap.push(nums[i]);
        if(minheap.size()>n){
            sum-=minheap.top();
            minheap.pop();
        }
        rightmax[i] = sum;
     }
     long long minsum=LLONG_MAX;
     for(int i=n-1;i<2*n;i++){
        long long diff=leftmin[i]-rightmax[i+1];
        minsum = min(minsum, diff);
     } 
     return minsum;
    }
};