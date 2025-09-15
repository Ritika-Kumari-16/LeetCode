class Solution {
public:
void findpse(vector<int>& arr , vector<int>&pse){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        if(!st.empty()) pse[i]=st.top();
        st.push(i);
    }
}
void findnse(vector<int>&arr , vector<int>&nse){
    stack<int>st;
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        if(!st.empty()) nse[i]=st.top();
        st.push(i);
    }
}
int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n= arr.size();
        vector<int>pse(n,-1);
        findpse(arr,pse);
        vector<int>nse(n,n);
        findnse(arr,nse);
        long long totalsum=0;
        for(int i=0;i<n;i++){
            int el=arr[i];
            int left=i-pse[i];
            int right=nse[i]-i;
            long long totalsubarray= (1LL*left*right)%mod;
            totalsum=(totalsum+ (1LL* totalsubarray*el)%mod)%mod;
        }
        return totalsum;
    }
};