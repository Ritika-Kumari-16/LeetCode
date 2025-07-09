class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>temp(26,0);
        for(int i=0;i<tasks.size();i++){
            temp[tasks[i]-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(temp[i]>0) pq.push(temp[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp1;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp1.push_back(freq);
                }
            }
            for(auto it:temp1){
                if(it>0) pq.push(it);
            }
            if(pq.empty()){
                time+=temp1.size();
            }
            else{
                time+=(n+1);
            }
        }
        return time;
    }
};