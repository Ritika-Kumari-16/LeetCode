class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxtypes, int truckSize) {
        int n= boxtypes.size();
        sort(boxtypes.begin(),boxtypes.end(),[](const vector<int>&a , const vector<int>&b) 
        { return a[1]>b[1]; }
        );
        int ans=0;
        for(int i=0;i<n;i++){
            if(truckSize==0) break;
            if(boxtypes[i][0]<=truckSize){
                ans+=(boxtypes[i][0]*boxtypes[i][1]);
                truckSize-=boxtypes[i][0];
            }
            else{
                ans+=(boxtypes[i][1]*truckSize);
                truckSize=0;
            }
        }
        return ans;
        
    }
};