class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n= nums1.size();
        int m=nums2.size();
        vector<int>nge(m,-1);
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]) st.pop();
            if(!st.empty()) nge[i]=st.top();
            st.push(nums2[i]);
        }
        unordered_map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[nums2[i]]=nge[i];
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};