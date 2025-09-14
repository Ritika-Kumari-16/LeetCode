class MyQueue {
public:
stack<int>st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int s=st1.size();
        if(s==0) return -1;
        stack<int>temp;
        for(int i=0;i<s-1;i++){
            temp.push(st1.top());
            st1.pop();
        }
        int el=st1.top();
        st1.pop();
        for(int i=0;i<s-1;i++){
            st1.push(temp.top());
            temp.pop();
        }
        return el;
    }
    
    int peek() {
        int s=st1.size();
        if(s==0) return -1;
        stack<int>temp;
        for(int i=0;i<s-1;i++){
            temp.push(st1.top());
            st1.pop();
        }
        int el=st1.top();
        temp.push(el);
        st1.pop();
        for(int i=0;i<s;i++){
            st1.push(temp.top());
            temp.pop();
        }
        return el;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */