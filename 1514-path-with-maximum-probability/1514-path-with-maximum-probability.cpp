class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succpro, int start, int end) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succpro[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        vector<double>prob(n,0.0);
        priority_queue<pair<double,int>>pq;
        prob[start]=1.0;
        pq.push({1.0,start});
        while(!pq.empty()){
            auto [curr,node]=pq.top();
            pq.pop();
            if(node==end) return curr;
            if(curr<prob[node]) continue;
            for(auto[neig,pro]:adj[node]){
                double newp=pro*curr;
                if(newp>prob[neig]){
                    prob[neig]=newp;
                    pq.push({newp,neig});
                }
            }
        }
        return 0.0;
    }
};