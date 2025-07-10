class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int sz=1;
        if(st.empty() || st.top().first > price){
            st.push({price,sz});
        }
        else{
            while(!st.empty() && st.top().first <= price ){
                sz+=st.top().second;
                st.pop();
            }
            st.push({price,sz});
        }
        return sz;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */