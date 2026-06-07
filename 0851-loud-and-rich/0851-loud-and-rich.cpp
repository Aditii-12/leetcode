class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(auto it:richer){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        vector<int>ans(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nei:adj[node]){
                if(quiet[ans[node]]<quiet[ans[nei]])
                    ans[nei]=ans[node];
                indegree[nei]--;
                if(indegree[nei]==0) q.push(nei);
            }
        }
        return ans;
    }

};