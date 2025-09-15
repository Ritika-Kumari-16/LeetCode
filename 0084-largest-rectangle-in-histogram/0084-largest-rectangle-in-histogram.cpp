class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        long long maxarea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int el=heights[st.top()];
                st.pop();
                int left= st.empty() ? -1: st.top();
                int maxlen=(i-left)-1;
                long long area=maxlen*el;
                maxarea=max(maxarea,area);
            }
            st.push(i);
        }
        while(!st.empty()){
            int right= n;
            int el=heights[st.top()];
            st.pop();
            int left= st.empty()?-1:st.top();
            int maxlen= (right-left)-1;
            long long area=maxlen*el;
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};