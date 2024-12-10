#include<iostream>
using namespace std;
class Solution {
public:
    int maximumLength(string s) {
        if(s.size()<3){
            return -1;
        }
        int n= s.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            string temp="";
            temp+=s[i];
            mp[temp]++;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[j-1]){
                    temp+=s[j];
                    mp[temp]++;
                }
                else{
                    break;
                }
            }
        }
        int leng=INT_MIN;
        for(auto it : mp){
            if(it.second>=3){
                string st=it.first;
                int val=st.size();
                leng = max (leng , val );
            }
        }
        if(leng==INT_MIN){
            return -1;
        }
        return leng;
    }
};

