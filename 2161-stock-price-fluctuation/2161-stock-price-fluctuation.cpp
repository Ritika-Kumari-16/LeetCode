class StockPrice {
public:
    multiset<int>st;
    unordered_map<int,int>mpp;
    int curtimestamp;
    StockPrice() {
        st.clear();
        mpp.clear();
        curtimestamp=0;
    }
    
    void update(int timestamp, int price) {
        if(mpp.find(timestamp)!=mpp.end()){
            int prevprice=mpp[timestamp];
            st.erase(st.find(prevprice));
        }
        mpp[timestamp]=price;
            st.insert(price);
        curtimestamp=max(timestamp,curtimestamp);
    }
    
    int current() {
        return mpp[curtimestamp];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */