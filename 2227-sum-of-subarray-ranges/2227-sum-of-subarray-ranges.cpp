class Solution {
public:
    void ngeidx(vector<int>&arr , vector<int>&nge ){
        int n = arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] <arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(i);
        }
    }
    void pgeidx(vector<int>&arr , vector<int>&pge ){
        int n = arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] <=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pge[i]=st.top();
            }
            st.push(i);
        }
    }
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        long long total=0;
        vector<int>nge(n,n);
        vector<int>pge(n,-1);
        ngeidx(arr,nge);
        pgeidx(arr,pge);
        for(int i=0;i<n;i++){
            int el= arr[i];
            int left=i-pge[i];
            int right= nge[i]-i;
            total=(total+(left*right*1ll * el));
        }
        return total;
    }
    void nseidx(vector<int>&arr , vector<int>&nse ){
        int n = arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
    }
    void pseidx(vector<int>&arr , vector<int>&pse ){
        int n = arr.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
    }
    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long total=0;
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        nseidx(arr,nse);
        pseidx(arr,pse);
        for(int i=0;i<n;i++){
            int el= arr[i];
            int left=i-pse[i];
            int right= nse[i]-i;
            total+=(left*right*1ll * el);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};