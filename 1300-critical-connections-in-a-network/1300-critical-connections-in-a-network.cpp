class Solution {
public:
    int timestamp = 1;

    void dfs(int node, int parent, vector<vector<int>>& adjlist, vector<int>& time,
             vector<int>& low, vector<int>& visited, vector<vector<int>>& bridges) {

        visited[node] = 1;
        time[node] = low[node] = timestamp++;

        for (auto adj : adjlist[node]) {
            if (adj == parent) continue;

            if (!visited[adj]) {
                dfs(adj, node, adjlist, time, low, visited, bridges);

                // After returning, update low time
                low[node] = min(low[node], low[adj]);

                // Bridge condition
                if (low[adj] > time[node]) {
                    bridges.push_back({node, adj});
                }
            } else {
                // Back edge
                low[node] = min(low[node], time[adj]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjlist(n);
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }

        vector<int> time(n, -1), low(n, -1), visited(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, adjlist, time, low, visited, bridges);
        return bridges;
    }
};
