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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
       vector<vector<int>> prefixheight(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    prefixheight[i][j]=0;
                }
                else{
                    prefixheight[i][j]=1;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    prefixheight[i][j]=0;
                }
                else{
                    prefixheight[i][j]=prefixheight[i-1][j]+1;
                }
            }
        }
        int maxarearec=0;
        for(int i=0;i<n;i++){
            maxarearec=max(maxarearec,largestRectangleArea(prefixheight[i]));
        }
        return maxarearec;
    }
};