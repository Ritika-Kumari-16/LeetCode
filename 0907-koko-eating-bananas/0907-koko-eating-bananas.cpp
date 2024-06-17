#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long fun(vector<int>&piles , int hourly){
    long long reqtime=0;
    for(int i=0;i<piles.size();i++){
    reqtime+=ceil((double)piles[i]/ hourly);
    }
    return reqtime;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mid;
        int low= 1;
        int high=*max_element(piles.begin(),piles.end());
        int ans =high;
        while(low<=high){
            mid=low+(high-low)/2;
            long long totalhrs=fun(piles,mid);
            if(totalhrs>h){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};