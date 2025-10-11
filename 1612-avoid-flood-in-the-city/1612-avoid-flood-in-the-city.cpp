class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n= rains.size();
        vector<int>ans(n,1);
        unordered_map<int,int>mpp;
        set<int>st;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                st.insert(i);
            }
            else{
                ans[i]=-1;
                if(mpp.count(rains[i])){
                    auto idx = st.lower_bound(mpp[rains[i]]);
                    if(idx==st.end()){
                        return {};
                    }
                    else{
                        ans[*idx]=rains[i];
                        st.erase(idx);
                    }
                }
                mpp[rains[i]]=i;
                
            }
        }
        return ans;
    }
};