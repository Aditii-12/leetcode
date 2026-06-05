class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;
    void dfs(int node,vector<vector<int>>& graph){
        path.push_back(node);
        int target=graph.size()-1;
        if(node==target){
            ans.push_back(path);
        }
        else{
            for(auto neigh:graph[node]){
                dfs(neigh,graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,graph);
        return ans;
    }
};