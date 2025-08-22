class Solution {
public:
    bool func(unordered_map<int,vector<int>>&adj,int node,vector<int>& color){ 
        //this functipn to check if graph is biparitie
        queue<int>q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto it:adj[u]){
                if(color[it]==color[u]) return false;
                if(color[it]==-1){
                    color[it]=1-color[u];
                    q.push(it);
                }
            }
        }
        return 1;
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto it:dislikes){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n+1,-1);
        for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(!func(adj,i,color)) return 0;
        }
        }
        return 1;
    }
};