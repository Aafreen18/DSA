class Solution {
public:

    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {

        // adjacency list
        vector<vector<pair<int, int>>> adj(V);

        // {neighbor, weight}
        for (auto edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        // -------------------------
        // STEP 1: Calculate indegree
        // -------------------------

        vector<int> indegree(V, 0);

        for (int u = 0; u < V; u++) {

            for (auto edge : adj[u]) {

                int v = edge.first;

                indegree[v]++;
            }
        }

        // -------------------------
        // STEP 2: Kahn's Algorithm
        // -------------------------

        queue<int> q;

        for (int i = 0; i < V; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto edge : adj[node]) {

                int neighbor = edge.first;

                indegree[neighbor]--;

                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // -------------------------
        // STEP 3: Shortest distance
        // -------------------------

        const int INF = 1e9;

        vector<int> dist(V, INF);

        dist[src] = 0;

        // Process nodes in topological order
        for (int node : topo) {

            // If node is unreachable, don't process it
            if (dist[node] == INF)
                continue;

            for (auto edge : adj[node]) {

                int neighbor = edge.first;
                int wt = edge.second;

                if (dist[node] + wt < dist[neighbor]) {

                    dist[neighbor] = dist[node] + wt;
                }
            }
        }

        // Convert unreachable nodes to -1
        for (int i = 0; i < V; i++) {

            if (dist[i] == INF) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
