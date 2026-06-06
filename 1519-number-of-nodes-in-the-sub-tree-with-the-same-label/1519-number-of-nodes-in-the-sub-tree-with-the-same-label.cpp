class Solution {
public:
vector<int>ans;
    vector<int> dfs(int node,int par,vector<vector<int>>& adj,string& labels){
        vector<int>freq(26,0);
        freq[labels[node]-'a']++;
        for(auto it:adj[node]){
            if(it==par) continue;
            vector<int>childfr=dfs(it,node,adj,labels);
            for(int i=0;i<26;i++){
                freq[i]+=childfr[i];
            }
        }
        ans[node]=freq[labels[node]-'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        ans.resize(n);
        dfs(0,-1,adj,labels);
        return ans;
    }
};