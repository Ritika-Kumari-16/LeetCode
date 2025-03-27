class Solution {
public:
    vector<int> nextsmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }

    vector<int> prevsmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> u(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            u[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return u;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        int mod = 1e9 + 7;
        
        vector<int> nxtsml = nextsmaller(arr);
        vector<int> prevsml = prevsmaller(arr);

        for (int i = 0; i < n; i++) {
            int right = nxtsml[i] - i;
            int left = i - prevsml[i];
            total = (total + (1LL * right * left * arr[i]) % mod) % mod;
        }
        return total;
    }
};