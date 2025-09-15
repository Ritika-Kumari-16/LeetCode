class StockSpanner {
public:
stack<pair<int,int>>st;
    StockSpanner() {
    }
    
    int next(int price) {
        int spans=1;
        if(st.empty()){
            st.push({price,spans});
        }else{
            while(!st.empty() && st.top().first<=price){
                spans=spans+(st.top().second);
                st.pop();
            }
            st.push({price,spans});
        }
        return spans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */