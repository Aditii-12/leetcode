class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int>outd(n,0);
        for(int u=0;u<n;u++){
            outd[u]=graph[u].size();
            for(auto it:graph[u]){
                adj[it].push_back(u);
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(outd[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                outd[it]--;
                if(outd[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};