class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for (auto &it : roads) {
            int u = it[0], v = it[1], c = it[2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        using P = pair<long long,int>; 
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> dist(n, LLONG_MAX);  // shortest time to reach node
        vector<int> pathcnt(n, 0);              // number of shortest paths
        dist[0] = 0;
        pathcnt[0] = 1;
        pq.push({0,0});
        while (!pq.empty()) {
            long long curr = pq.top().first; 
            int node = pq.top().second;
            pq.pop();
            if (curr > dist[node]) continue;
            for (auto &[neigh, timee] : adj[node]) {
                long long nd = curr + timee;
                if (nd < dist[neigh]) {
                    dist[neigh] = nd;
                    pathcnt[neigh] = pathcnt[node];
                    pq.push({nd, neigh});
                } 
                else if (nd == dist[neigh]) {
                    pathcnt[neigh] = (pathcnt[neigh] + pathcnt[node]) % MOD;
                }
            }
        }
        return pathcnt[n-1];
    }
};
