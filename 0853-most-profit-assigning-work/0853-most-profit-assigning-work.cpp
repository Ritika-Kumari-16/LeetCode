class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        long long totalprofit = 0;
        for (int i = 0; i < worker.size(); i++) {
            int index = -1;
            long long preprofit=0;
            long long postprofit=0;
            for (int j = 0; j < difficulty.size(); j++) {
                if (difficulty[j] <= worker[i]) {
                    postprofit=profit[j];
                    if(postprofit>=preprofit){
                        preprofit=postprofit;
                        index = j;
                    }
                }
            }
            if (index == -1) {
                totalprofit += 0;
            } else {
                totalprofit += profit[index];
            }
        }
        return totalprofit;
    }
};