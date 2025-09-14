#include <stack>
#include <climits>

class MinStack {
public:
    std::stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                long long encodedVal = 2LL * val - mini;
                st.push(encodedVal);
                mini = val;
            }
        }
    }
    
    void pop() {
        long long topVal = st.top();
        st.pop();
        
        if (topVal >= mini) {
            // mini remains the same
        } else {
            mini = 2LL * mini - topVal;
        }
    }
    
    int top() {
        long long topVal = st.top();
        if (topVal >= mini) {
            return (int)topVal;
        } else {
            return (int)mini;
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};
