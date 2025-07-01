class Solution {
public:
    vector<string> findWords(vector<string>& words)
    {
        //brute force approach
        //time complexity:O(m*n)
        //space complexity:O(m*n)

        int i;    
        //frequency arrya to map each letter to keyboard row
        int alpha[26]={0};
        vector<string> ans; 

        //keyboard rows
        string key_rows[3]= {"qwertyuiop" , "asdfghjkl" , "zxcvbnm"};

        //loop to map each character to its keyboard_row
        for(int i=0;i<3;i++)
        {
            for(char ch: key_rows[i])
                alpha[ch-'a']=i+1;      //assigning row_number
        }

        //checking each word if all characters fall in the same row
        for(string s:words)
        {
            i=0;
            int n=s.size();

            //moving through the 'current-word' if all characters are in the same row
            while((i<n) && ((alpha[tolower(s[i]) - 'a']) == alpha[tolower(s[0]) - 'a']))
                i++;

            //if all characters of 'current-word' are in the same row, insert it in 'ans'
            if(i==n)
                ans.push_back(s);
        }
        return ans;
    }
};