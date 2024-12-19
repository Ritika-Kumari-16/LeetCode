class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 1;
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = arr[0];
        right[n-1] = arr[n-1];

        for(int i = 1;i < n;i++){
            left[i] = max(left[i-1],arr[i]);
            right[n-i-1] = min(right[n-i],arr[n-i-1]);
        }

        for(int i = 0;i < n-1;i++){
            if(left[i] <= right[i+1]){
                ans++;
            }
        }
        return ans;
    }
};