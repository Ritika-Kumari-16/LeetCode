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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            prefix[0][i]=matrix[0][i]-'0';
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    prefix[i][j]=0;
                }
                else{
                    prefix[i][j]=prefix[i-1][j]+1;
                }
            }
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largestRectangleArea(prefix[i]));
        }
        return maxarea;
    }
};