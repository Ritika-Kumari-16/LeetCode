class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                int nsidx=i;
                int el= heights[st.top()];
                st.pop();
                int psidx= st.empty()?-1:st.top();
                maxarea=max(maxarea,(nsidx-psidx-1)*el);
            }
            st.push(i);
        }
        while(!st.empty()){
                int nsidx=n;
                int el= heights[st.top()];
                st.pop();
                int psidx= st.empty()?-1:st.top();
                maxarea=max(maxarea,(nsidx-psidx-1)*el);
            }
            return maxarea;
    }
};