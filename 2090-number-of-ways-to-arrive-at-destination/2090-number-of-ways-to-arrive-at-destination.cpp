class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Use long long for distance
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0}); // {distance, node}

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& it : adj[node]) {
                int adjnode = it.first;
                int adjdist = it.second;

                if (dist[adjnode] > time + adjdist) {
                    dist[adjnode] = time + adjdist;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                } else if (dist[adjnode] == time + adjdist) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
