class FindSumPairs {
public:
    unordered_map<int,int>mpp;
    vector<int>num1;
    vector<int>num2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        num1=nums1;
        num2=nums2;
        for(int i=0;i<nums2.size();i++){
            mpp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        int value=num2[index];
        mpp[value]--;
        int newval=value+val;
        num2[index]=newval;
        mpp[newval]++;
    }
    
    int count(int tot) {
        int totalcnt=0;
        for(int i=0;i<num1.size();i++){
            int val=num1[i];
            int reqval=tot-val;
            totalcnt+=mpp[reqval];
        }
        return totalcnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */