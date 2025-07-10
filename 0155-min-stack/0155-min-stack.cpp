class MinStack {
    stack<long>st;
    int minimum;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minimum=val;
        }
        else{
            if(val<minimum){
                long num= 2L*val-minimum;
                st.push(num);
                minimum=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return ;
        if(st.top()<minimum){
            minimum= 2L*minimum-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<minimum) return minimum;
        return st.top();
    }
    
    int getMin() {
        return minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */