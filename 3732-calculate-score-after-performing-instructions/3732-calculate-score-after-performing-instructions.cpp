class Solution {
public:
typedef long long ll;
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n= values.size();
        vector<int>visited(n,-1);
        ll score=0;
        int i=0;
        while(i>=0 && i<n){
            if(visited[i]!=-1) break;
            if(instructions[i]=="add"){
                score+=values[i];
                visited[i]=1;
                i++;
            }
            else if (instructions[i]=="jump"){
                visited[i]=1;
                i=(i+values[i]);

            }
        }
        return score;
    }
};