class Solution {
public:
    int minimumLength(string s) {
        vector<int> Freq(26, 0);
        int totalLen = 0;
        for (char currentChar : s) {
            Freq[currentChar - 'a']++;
        }
        for (int frequency : Freq) {
            if (frequency == 0) continue;
            if (frequency % 2 == 0) {
                totalLen += 2;  // If frequency is even, add 2
            } else {
                totalLen+= 1;  // If frequency is odd, add 1
            }
        }

        return totalLen;
    }
};