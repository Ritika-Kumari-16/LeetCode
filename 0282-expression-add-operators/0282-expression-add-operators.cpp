class Solution {
public:
    void helper(int i, const string &num,
                long long target, long long eval, long long last,
                string temp, vector<string>& ans) {
        if (i == (int)num.size()) {
            if (eval == target) ans.push_back(temp);
            return;
        }

        long long val = 0;
        string s;
        for (int j = i; j < (int)num.size(); ++j) {
            if (j > i && num[i] == '0') break; // don't allow numbers with leading zeros
            s.push_back(num[j]);
            val = val * 10 + (num[j] - '0');

            if (i == 0) {
                // first number (no operator)
                helper(j + 1, num, target, val, val, s, ans);
            } else {
                helper(j + 1, num, target, eval + val, val, temp + "+" + s, ans);
                helper(j + 1, num, target, eval - val, -val, temp + "-" + s, ans);
                helper(j + 1, num, target, (eval - last) + last * val, last * val, temp + "*" + s, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(0, num, (long long)target, 0LL, 0LL, "", ans);
        return ans;
    }
};
