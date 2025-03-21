class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
        int n= intervals.size();
        vector<vector<int>>result;
        int i=0;
        while(i<n && intervals[i][1]<newIntervals[0]){
            result.push_back(intervals[i]);
            i++;
        }
        while(i<n && newIntervals[1]>=intervals[i][0]){
            newIntervals[0]=min(newIntervals[0],intervals[i][0]);
            newIntervals[1]=max(newIntervals[1],intervals[i][1]);
            i++;
        }
        result.push_back(newIntervals);
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};