class MedianFinder {
public:
priority_queue<int>leftheap;
priority_queue<int,vector<int>,greater<int>>rightheap;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(leftheap.empty() || leftheap.top()>=num){
            leftheap.push(num);
            if(leftheap.size()>rightheap.size()+1){
                rightheap.push(leftheap.top());
                leftheap.pop();
            }
        }
        else{
            rightheap.push(num);
            if(rightheap.size()>leftheap.size()){
                leftheap.push(rightheap.top());
                rightheap.pop();
            }
        }
    }
    
    double findMedian() {
        if(leftheap.size()==rightheap.size()){
            return (double)(leftheap.top()+rightheap.top())/2.0;
        }
        return (double)leftheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */