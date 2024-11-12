class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        // if(n==1) return ans.push_back(0);
        if(n%2==0){
            n=n/2;
            for(int i=1;i<=n;i++){
            ans.push_back(-i);
            ans.push_back(i);
            }
        }
        else{
            n=n/2;
            ans.push_back(0);
            for(int i=1;i<=n;i++){
            ans.push_back(-i);
            ans.push_back(i);
            }
        }
        return ans;
    }
};