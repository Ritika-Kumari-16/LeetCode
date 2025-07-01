class Solution {
public:
    string finalString(string s) {
        int pointer = 0;
        int n = s.size();
        string ans;
        while (pointer < n) {
            if (s[pointer] == 'i') {
                reverse(ans.begin(), ans.end());
            } else {
                ans.push_back(s[pointer]);
            }
            pointer++;
        }
        return ans;
    }
};