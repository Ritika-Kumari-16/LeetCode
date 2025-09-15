class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(k>0 && !st.empty() &&  st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k-- && !st.empty()){
            st.pop();
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        while(!ans.empty() && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans.empty() ? "0" : ans;
        
    }
};