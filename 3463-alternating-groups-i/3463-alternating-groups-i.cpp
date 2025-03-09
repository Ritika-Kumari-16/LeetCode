class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        if(colors.size()<3) return 0;
        int n = colors.size();
        int cnt=0;
        for( int i=0;i<=n-3;i++){
            int fl=1;
            for(int j=i+1 ; j<i+3;j++){
                if(colors[j-1]==colors[j]) fl=0;

            }
            cnt+=fl;
        }
        if(colors[n-1]!=colors[0] && colors[0]!=colors[1])
        {
            cnt++;
        }
        if(colors[n-2]!=colors[n-1] && colors[n-1]!=colors[0])
        {
            cnt++;
        }
        return cnt;
    }
};