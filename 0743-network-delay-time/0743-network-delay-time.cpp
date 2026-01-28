class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1, INT_MAX);
        result[k] = 0;
	    pq.push({0, k}); 
        //we r pushing cost and then node
        while(!pq.empty()){
            int d  = pq.top().first;
	        int node = pq.top().second;
	        pq.pop();
            if (d > result[node]) continue;
            for(auto &vec : adj[node]) {
		    int it= vec.first; //it is node
		    int dist= vec.second;
		        if(d + dist < result[it]) {
		            result[it] = d + dist;
		            pq.push({d+dist,it});
		        }
	        }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++)
            ans = max(ans, result[i]);
	    return ans==INT_MAX?-1:ans;
    }
};