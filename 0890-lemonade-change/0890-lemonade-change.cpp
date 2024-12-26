class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivecoins=0;
        int tencoins=0;
        int n= bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5) fivecoins++;
            if(bills[i]==10) {
                if(fivecoins){
                    fivecoins--;
                    tencoins++;
                }
                else{
                    return false;
                }
            }
            if(bills[i]==20) {
                if(fivecoins && tencoins){
                    fivecoins--;
                    tencoins--;
                }
                else if(fivecoins>=3){
                    fivecoins-=3;
                    
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};