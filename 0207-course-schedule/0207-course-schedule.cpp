class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            cnt++;
            for(auto neig:adj[it]){
                indegree[neig]--;
                if(indegree[neig]==0) q.push(neig);
            }
        }
        return cnt==n;
    }
};