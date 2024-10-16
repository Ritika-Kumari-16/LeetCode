class Solution {
public:
    string reorganizeString(string s) {
        sort(s.begin(),s.end());
        string ans=s;
        int n=s.length();
        auto cmp = [](pair<int,int> a, pair<int,int> b){
            return a.first < b.first;
        };
        priority_queue<pair<int,char>, vector<pair<int,char>>, decltype(cmp)> pq(cmp);
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                pq.push({cnt,s[i]});
                cnt=1;
            }
        }
        int x=0;
        pq.push({cnt,s[n-1]});
        if(pq.top().first>(n+1)/2) return "";
        
        while(!pq.empty()){
            pair<int,char> test = pq.top();
            for(int i=1;i<=test.first;i++){
                if(x>=n) x=1;
                ans[x]=test.second;
                x+=2;
            }
            pq.pop();
        }
        return ans;
    }
};