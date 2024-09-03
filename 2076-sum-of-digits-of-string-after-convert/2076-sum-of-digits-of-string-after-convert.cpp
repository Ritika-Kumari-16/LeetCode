class Solution {
    public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char ch : s) {
            int a = ch - 96;
            sum += a % 10;      // First digit
            a /= 10;
            sum += a;    // Second digit 
        }
        k--;   // One Transform operation is done
        while (k > 0) {
            int temp = sum;
            sum = 0;
            while (temp != 0) {
                sum += temp % 10;
                temp /= 10;
            }
            k--;
        }
        return sum;
    }
};