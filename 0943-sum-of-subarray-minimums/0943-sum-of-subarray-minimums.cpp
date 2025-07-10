class Solution {
public:
    int mod=1e9+7;
    void nseidx(vector<int>&arr , vector<int>&nse ){
        int n = arr.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
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
            while(!st.empty() && arr[st.top()] >arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i]=st.top();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total=0;
        vector<int>nse(n,n);
        vector<int>pse(n,-1);
        nseidx(arr,nse);
        pseidx(arr,pse);
        for(int i=0;i<n;i++){
            int el= arr[i];
            int left=i-pse[i];
            int right= nse[i]-i;
            total=(total+(left*right*1ll * el)%mod)%mod;
        }
        return total;
    }
};