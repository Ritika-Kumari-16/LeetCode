class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxarea=0;
        int n= heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele= st.top();
                st.pop();
                int nse=i;
                int pse= st.empty() ? -1: st.top();
                maxarea=max(maxarea,heights[ele] * (nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse= n;
            int ele= st.top();
            st.pop();
            int pse= st.empty() ? -1:st.top();
            maxarea=max(maxarea,heights[ele] * (nse-pse-1));
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        vector<vector<int>>presum(n,vector<int>(m,0));
        int maxarea=0;
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(matrix[i][j]-'0');
                if(matrix[i][j]=='0') {sum=0;}
                presum[i][j]=sum;
            }
        }
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largestRectangleArea(presum[i]));
        }
        return maxarea;
    }
};