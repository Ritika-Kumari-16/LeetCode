class Twitter {
public:
unordered_map<int,unordered_set<int>>followeeslist;
unordered_map<int,vector<pair<int,int>>>usertweet;
int timestamp;
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        usertweet[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        for(auto it:usertweet[userId]){
            q.push(it);
        }
        for(auto it:followeeslist[userId]){
            for(auto t:usertweet[it]){
                q.push({t});
            }
        }
        int count=0;
        while(!q.empty() && count<10){
            ans.push_back(q.top().second);
            q.pop();
            count++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId== followeeId) return ;
        followeeslist[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followeeslist[followerId].count(followeeId)){
            followeeslist[followerId].erase(followeeId);}
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */