class Solution {
public:
    unordered_map<char, string> map {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    void comb(string digits , int ind , string temp2, vector<string>&ans ){
        if(ind==digits.size()) {
            ans.push_back(temp2);

            return ;}
        char c= digits[ind];
        string temp=map[c];
        for(int i=0;i<temp.size();i++){
            temp2+=temp[i];
            comb(digits,ind+1,temp2,ans);
            temp2.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty()) 
        {return ans;}
        string temp2="";
        comb(digits , 0 , temp2,ans);
        return ans;
    }
};