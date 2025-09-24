class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long long x = abs((long long)numerator), y = abs((long long)denominator);
        if (x % y == 0) return res + to_string(x / y);
        else {
            res += to_string(x / y);
            x %= y;
            res += '.';
        }
        unordered_map<int, int> hash;
        while (x) {
            if (hash.count(x)) {
                res.insert(hash[x], "(");
                res += ')';
                return res;
            } else {
                hash[x] = res.size();
                x *= 10;
                res += to_string(x / y);
                x %= y;
            }
        }
        return res;
    }
};