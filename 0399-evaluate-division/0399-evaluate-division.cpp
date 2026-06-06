class Solution {
public:
    double dfs(string src,string des, unordered_map<string,vector<pair<string,double>>>&adj,
    unordered_set<string>&vis){
        if(src==des) return 1.0;
        vis.insert(src);
        for(auto[nei,wt]:adj[src]){
            if(vis.count(nei)) continue;
            double val=dfs(nei,des,adj,vis);
            if(val!=-1) return val*wt;
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& eqns, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<eqns.size();i++){
            string u=eqns[i][0];
            string v=eqns[i][1];
            double wt=values[i];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,1.0/wt});
        }
        vector<double>ans;
        for(auto& q:queries){
            string src=q[0];
            string des=q[1];
            if(!adj.count(src)||!adj.count(des)) {
                ans.push_back(-1);
                continue;
            }
            unordered_set<string>vis;
            ans.push_back(dfs(src,des,adj,vis));
        }
        return ans;
    }
};