class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        int i = 0;
        stack<char> st;

        while (i < n) {
            if (s[i] != ']') {
                st.push(s[i]);
            } else {
                // Get the string between brackets
                string str = "";
                while (!st.empty() && st.top() != '[') {
                    str += st.top();
                    st.pop();
                }
                st.pop(); // Remove '['

                // Get the number
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr += st.top();
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end());
                int val = stoi(numStr);

                // Repeat the string
                reverse(str.begin(), str.end());
                string repeated = "";
                for (int j = 0; j < val; j++) {
                    repeated += str;
                }

                // Push repeated string back to stack
                for (char ch : repeated) {
                    st.push(ch);
                }
            }
            i++;
        }

        // Final result
        string decode = "";
        while (!st.empty()) {
            decode += st.top();
            st.pop();
        }
        reverse(decode.begin(), decode.end());
        return decode;
    }
};
