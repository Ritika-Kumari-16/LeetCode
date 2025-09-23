class Solution {
public:
unordered_map<char,string>mpp={
    {'0',""},{'1',""},{'2' , "abc"} , {'3',"def"} , {'4',"ghi"} ,{'5',"jkl"},{'6',"mno"} ,{'7',"pqrs"}
    ,{'8' ,"tuv"} ,{'9',"wxyz"}
};
void generatecomb(int i , int n , string &digits, string &temp , vector<string>&ans){
    if(i==n){
        ans.push_back(temp);
        return;
    }
    string s= mpp[digits[i]];
    for(int j=0;j<s.size();j++){
        temp+=s[j];
        generatecomb(i+1,n,digits,temp, ans);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        int n= digits.size();
        if(n==0) return {};
        vector<string>ans;
        string temp;
        generatecomb(0,n,digits,temp,ans);
        return ans;
    }
};