class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>ballcnt;
        unordered_map<int,int>ballcolor;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(ballcolor.find(ball)!=ballcolor.end()){
                int prevcolor=ballcolor[ball];
                ballcnt[prevcolor]--;
                if(ballcnt[prevcolor]==0){
                    ballcnt.erase(prevcolor);
                }
            }
            ballcolor[ball]=color;
            ballcnt[color]++;
            ans.push_back(ballcnt.size());
        }
        return ans;
    }
};