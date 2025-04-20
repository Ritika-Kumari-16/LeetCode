class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n= answers.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[answers[i]]++;
        }
        int count=0;
        for(auto &it :mp){
            int val= it.first;
            int freq= it.second;
            if(freq>val+1){
                int ad=freq/(val+1);
                count+=(val+1)*ad;
                freq=freq%(val+1); 
            }
            if( freq!=0 && freq<=val+1){
                count+=(val+1);
            }
        }
        return count;
    }
};