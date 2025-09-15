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

    long long sumSubarrayMins(vector<int>& arr) {
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
                long long totalsubarray= (1LL*left*right);
                totalsum=(totalsum+ (1LL* totalsubarray*el));
            }
            return totalsum;
        }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};