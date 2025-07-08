class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end());
            vector<vector<int>>mergedintervals;
            int n= intervals.size();
            for(int i=0;i<n;i++){
                if(mergedintervals.size()==0 || intervals[i][0]>mergedintervals.back()[1]){
                    mergedintervals.push_back(intervals[i]);
                }
                else{mergedintervals.back()[1]= max(mergedintervals.back()[1],intervals[i][1]);}
            }
            return mergedintervals;
        
    }
};