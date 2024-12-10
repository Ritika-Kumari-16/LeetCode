#include<iostream>
using namespace std;
class Solution {
public:
    int maximumLength(string s) {
        if(s.size()<3){
            return -1;
        }
        int n= s.size();
        map<pair<char,int>,int> mp;
        for(int i=0;i<n;i++){
            char temp=s[i];
            int lengt=1;
            mp[{temp,lengt}]++;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[j-1]){
                    lengt++;
                    mp[{temp,lengt}]++;
                }
                else{
                    break;
                }
            }
        }
        int leng=INT_MIN;
        for(auto &it : mp){
            if(it.second>=3){
                int val=it.first.second;
                leng = max (leng , val );
            }
        }
        if(leng==INT_MIN){
            return -1;
        }
        return leng;
    }
};

