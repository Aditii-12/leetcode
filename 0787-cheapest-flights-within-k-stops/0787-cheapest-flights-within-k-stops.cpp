class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX); //we will keep updating this
        unordered_map<int, vector<pair<int, int>>> adj; 
        for(vector<int> &vec : flights) {
            int u= vec[0];
            int v= vec[1];
            int cost = vec[2];  
            adj[u].push_back({v, cost});
        }
        queue<pair<int, int>> q; //node,dist
        q.push({src, 0});
        dist[src] = 0;
        int l = 0; //levels, we have to keep this equal or less than k
        while(!q.empty() && l <= k) {
            int size=q.size();
            while(size--) {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();
                for(pair<int, int> &P : adj[u]) {
                    int v    = P.first;
                    int cost = P.second;
                    if(dist[v] > d + cost) {
                        dist[v] = d + cost;
                        q.push({v, d+cost});
                    }
                }
            }
            l++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};