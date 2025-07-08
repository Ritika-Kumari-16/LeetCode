class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        if(n==1) return 1;
        vector<int>left(n,0);
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                left[i]=1;
            }
        }
        int rightval=1;
        int maxcandies=0;
        maxcandies+=(max(rightval,left[n-1]));
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                rightval+=1;
                
            }
            else{
                rightval=1;
            }
            maxcandies+=max(rightval,left[i]);
        }
        return maxcandies;
    }
};