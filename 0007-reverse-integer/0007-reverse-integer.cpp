class Solution {
public:
    int reverse(int x) {
        long reversed_value=0;
        while(x!=0){
            int remainder= x%10;
            reversed_value= reversed_value*10+ remainder;
            if(reversed_value > INT_MAX) return 0;
            if(reversed_value< INT_MIN) return 0;
            x=x/10;
        }
        return (int)reversed_value;
    }
};