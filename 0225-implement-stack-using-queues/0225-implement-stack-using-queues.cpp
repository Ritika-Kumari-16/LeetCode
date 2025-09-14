class MyStack {
public:
queue<int>q;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int s=q.size();
        if(s==0) return -1;
        for(int i=0;i<s-1;i++){
            q.push(q.front());
            q.pop();
        }
        int el=q.front();
        q.pop();
        return el;
    }
    
    int top() {
        int s=q.size();
        if(s==0) return -1;
        for(int i=0;i<s-1;i++){
            q.push(q.front());
            q.pop();
        }
        int el=q.front();
        q.pop();
        q.push(el);
        return el;
        
    }
    
    bool empty() {
        return q.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */