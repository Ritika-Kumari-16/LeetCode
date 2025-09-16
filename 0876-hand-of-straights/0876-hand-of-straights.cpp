class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n= hand.size();
        if((n%groupSize)!=0) return false;
        map<int,int>mpp;
        for(auto it:hand){
            mpp[it]++;
        }
        while(!mpp.empty()){
            int el=mpp.begin()->first;
            mpp[el]--;
            if(mpp[el]==0) mpp.erase(el);
            for(int i=1;i<groupSize;i++){
                if(mpp.find(el+1)==mpp.end()) return false;
                mpp[el+1]--;
                if(mpp[el+1]==0) mpp.erase(el+1);
                el++;
            }
        }
        return true;
    }
};