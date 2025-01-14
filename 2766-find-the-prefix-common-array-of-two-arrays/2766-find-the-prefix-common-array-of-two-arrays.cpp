class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n= A.size();
        vector<int>freq(n+1,0);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int count=0;
            freq[A[i]]++;
            freq[B[i]]++;
            for(int j=1;j<=n;j++){
                if(freq[j]==2){
                    count++;
                }
            }
            ans[i]=count;
        }
        return ans;
    }
};