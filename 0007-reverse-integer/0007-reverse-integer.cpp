class Solution {
public:
    int reverse(int x) {
        int reversed_value=0;
        while(x!=0){
            int remainder= x%10;
            if(reversed_value > INT_MAX/10 || reversed_value==INT_MAX && remainder >7) return 0;
            if(reversed_value < INT_MIN/10 || reversed_value==INT_MIN && remainder<-8) return 0;
            reversed_value= reversed_value*10+ remainder;
            x=x/10;
        }
        return reversed_value;
    }
};