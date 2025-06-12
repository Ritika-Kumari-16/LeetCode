class Solution {
public:
    int minheight(int i , int n , vector<vector<int>>&books ,int remainingwidth, int shelfWidth,int maxheight,vector<vector<int>>&dp){
        if(i>=n) return maxheight;
        if(dp[i][remainingwidth]!=-1) return dp[i][remainingwidth];
        int height=books[i][1];
        int width=books[i][0];
        //samelevel
        int samelevelheight=INT_MAX;
        if(width<=remainingwidth){
            samelevelheight= minheight(i+1,n,books,remainingwidth-width,shelfWidth,max(maxheight,height),dp);
        }
        //nextlevel
        int nxtlevelheight=maxheight+(minheight(i+1,n,books,shelfWidth-width,shelfWidth,height,dp));
        return dp[i][remainingwidth]=min(nxtlevelheight,samelevelheight);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<vector<int>>dp(n+1,vector<int>(shelfWidth+1,-1));
        return minheight(0,books.size(),books,shelfWidth,shelfWidth,0,dp);
    }
};