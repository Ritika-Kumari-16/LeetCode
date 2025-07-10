class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int m= nums1.size();
        int n= nums2.size();
        vector<int>nge(n,-1);
        for(int i= n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            nge[i]= st.empty()? -1 : st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums2[i]]=nge[i];
        }
        vector<int>ans(m,-1);
        for(int i=0;i<m;i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};