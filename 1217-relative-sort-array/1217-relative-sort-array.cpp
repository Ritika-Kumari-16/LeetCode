class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        vector<int>visitedarr(n,-1);
        vector<int>ans;
        vector<int>leftele;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr1[j] == arr2[i]) {
                    ans.push_back(arr1[j]);
                    visitedarr[j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visitedarr[i]==-1){
                leftele.push_back(arr1[i]);
            }
        }
        sort(leftele.begin(),leftele.end());
        for(int i =0;i<leftele.size();i++){
            ans.push_back(leftele[i]);
        }
        return ans;

    }
};