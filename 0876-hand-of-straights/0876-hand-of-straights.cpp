class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize) return false;
        map<int,int>mpp;
        for(auto &it:hand){
            mpp[it]++;
        }
        while(!mpp.empty()){
            int cur= mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp.find(cur+i)==mpp.end()) return false;
                mpp[cur+i]--;
                if(mpp[cur+i]==0) mpp.erase(cur+i);
            }
        }
        return true;
    }
};