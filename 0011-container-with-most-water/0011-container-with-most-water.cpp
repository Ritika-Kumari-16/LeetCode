class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r = n-1;
        int maxarea=0;
        while(l<r){
            maxarea=max(maxarea, (r-l)* min(height[l],height[r]));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};