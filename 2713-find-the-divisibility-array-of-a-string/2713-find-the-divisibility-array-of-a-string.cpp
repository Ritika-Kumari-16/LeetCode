#include<bits/stdc++.h>
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        
        string str= "", rem = "";
        for(int i=0; i<word.size(); i++){
            str += word[i];
            
            stringstream ss;
            long long num;
            
            ss << str;
            ss >> num;
            
            // int num = stoi(str);
            if(num%m==0) str = "";
            else str = to_string(num%m);
            
            res.push_back(!(num%m));
        }
        
        return res;
    }
};

//<!-- If you find it helpful, do upvote:) -->