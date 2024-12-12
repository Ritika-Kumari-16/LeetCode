class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n= gifts.size();
        while(k>0){
            int maxel=gifts[0];
            int idx=0;
            for(int i=0;i<n;i++){
                if(gifts[i]>maxel){
                    maxel=gifts[i];
                    idx=i;
                }
            }
            gifts[idx]=floor(sqrt(maxel));
            k--;
        }
        return accumulate(gifts.begin(),gifts.end(),0ll);
        
    }
};