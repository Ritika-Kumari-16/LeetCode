class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>minheap;
int kthscore;
    KthLargest(int k, vector<int>& nums) {
        kthscore=k;
        for(auto it:nums){
            minheap.push(it);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size()>kthscore) minheap.pop();
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */