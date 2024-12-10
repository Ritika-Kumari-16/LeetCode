class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int colsize= strs[0].size();
        int rowsize=strs.size();
        int count=0;
        for(int i=0;i<colsize;i++){
            for(int j=1;j<rowsize;j++){
                if(strs[j][i]<strs[j-1][i]){
                    count++;
                    break;
                }

            }
        }
        return count;
    }
};