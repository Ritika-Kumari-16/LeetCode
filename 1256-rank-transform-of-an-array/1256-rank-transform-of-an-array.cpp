class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        
        // Min-heap with pair of (element, index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }

        int rank = 1;
        int prev = INT_MIN;
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            if (val != prev) {
                prev = val;
                res[idx] = rank;
                rank++;
            } else {
                res[idx] = rank - 1;
            }
        }

        return res;
    }
};
