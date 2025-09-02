class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<classes.size();i++){
            double passratio= (double) (classes[i][0]+1)/(double )(classes[i][1]+1);
            double initialpassratio = (double) classes[i][0]/(double )classes[i][1];
            double diff= passratio- initialpassratio;
            pq.push({diff , i});
        }
        while(extraStudents--){
            double maxdiff= pq.top().first;
            int classno= pq.top().second;
            pq.pop();
            classes[classno][0]++;
            classes[classno][1]++;
            double initialpassratio = (double) classes[classno][0]/(double )classes[classno][1];
            double passratio = (double) (classes[classno][0]+1)/(double ) (classes[classno][1]+1);
            double diff= passratio - initialpassratio;
            pq.push({diff,classno});
        }
        double maxavgratio=0;
        for(int i=0;i<classes.size();i++){
            maxavgratio+=(double ) classes[i][0]/(double )classes[i][1];
        }

        return (double ) maxavgratio/(double ) classes.size();
    }
};