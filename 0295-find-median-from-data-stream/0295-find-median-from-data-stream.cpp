class MedianFinder {
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxheap.empty() || num<maxheap.top()){
            maxheap.push(num);
        }
        else
            minheap.push(num);
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size()>maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        double median=0;
        if(minheap.size()==maxheap.size()){
            median= (double)(minheap.top()+maxheap.top())/2.0;
        }
        else{
            median=(double) maxheap.top();
        }
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */