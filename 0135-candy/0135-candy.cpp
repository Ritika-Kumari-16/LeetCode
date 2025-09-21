class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();
        int totalcandies=1;
        int i=1;
        while(i<n){
            while(i<n && ratings[i-1]==ratings[i]){
                totalcandies++;
                i++;
            }
            int peak=1;
            while(i<n && ratings[i-1]<ratings[i]){
                peak+=1;
                totalcandies+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i-1]>ratings[i]){
                totalcandies+=down;
                down++;
                i++;
            }
            if(down>peak){
                totalcandies+=(down-peak);
            }
        }
        return totalcandies;
        
    }
};