class Solution {
public:
    string largestOddNumber(string nums) {
        int n= nums.size();
        int i=n-1;
        while(!nums.empty() || i>0){
            int val=nums[i]-'0';
            if(val%2==0) {
                nums.pop_back();
                i--;}
            else{
                return nums;
            }
        }
        return "";
    }
};