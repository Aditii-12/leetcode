class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<bool>>q(n,vector<bool>(n,0));
        for(auto &it:pre){
            int u=it[0];
            int v=it[1];
            q[u][v]=1;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    q[i][j]=q[i][j] || (q[i][k] && q[k][j]);
                }
            }
        }
        vector<bool>ans;
        for(auto &it:queries){
            if(q[it[0]][it[1]]==1) ans.push_back(1);
            else ans.push_back(0);
        }
        return ans;
    }
};