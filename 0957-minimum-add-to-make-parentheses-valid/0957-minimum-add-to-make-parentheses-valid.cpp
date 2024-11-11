class Solution {
public:
    int minAddToMakeValid(string s) {
        int countopening=0;
        int countclosing=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                countopening++;
            }
            else{if (countopening <=0){
                countclosing++;}
                else{
                    countopening--;
                }
            }
        
        }
        return countopening + countclosing;
    }
};