class Solution {
public:
    int passThePillow(int n, int time) {
        int count=0;
        int i=1;
        while(count<=time){
            while(i<=n){
                if(count==time) return i;
                count++;
                i++;
            }
            int j=n-1;
            while(j>=2){
                if(count==time) return j;
                count++;
                j--;
            }
            i=1;
        }
        return -1;
        
    }
};