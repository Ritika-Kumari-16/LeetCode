class Router {
public:
deque<vector<int>>q;
int maxsize;
unordered_map<int,vector<int>>mpp;
set<vector<int>>st;
    Router(int memoryLimit) {
        maxsize=memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.find({source,destination,timestamp})!=st.end()) return false;
        if(q.size()==maxsize){
            auto it=q.front();
            q.pop_front();
            st.erase({it[0],it[1],it[2]});
            auto &vec= mpp[it[1]];
            if(!vec.empty() && vec.front()==it[2]){
                vec.erase(vec.begin());
            }
        }
        st.insert({source,destination, timestamp});
        q.push_back({source,destination,timestamp});
        mpp[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.size()==0) return {};
        auto it=q.front();
        q.pop_front();
        st.erase({it[0],it[1],it[2]});
        auto &vec = mpp[it[1]];
        if (!vec.empty() && vec.front() == it[2]) {
            vec.erase(vec.begin()); // O(1)
        }

        return {it[0],it[1],it[2]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int lb= lower_bound(mpp[destination].begin(),mpp[destination].end(),startTime)-mpp[destination].begin();
        int ub=upper_bound(mpp[destination].begin(),mpp[destination].end(),endTime)-mpp[destination].begin();
        return ub-lb;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */