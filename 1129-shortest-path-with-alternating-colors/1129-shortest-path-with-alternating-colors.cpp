class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& reded, vector<vector<int>>& blueed) {
        vector<vector<int>>red(n);
        vector<vector<int>>blue(n);
        for(auto it:reded){
            red[it[0]].push_back(it[1]);
        }
        for(auto it:blueed){
            blue[it[0]].push_back(it[1]);
        }
        vector<int>ans(n,-1);
        queue<pair<int,int>>q;
        q.push({0,1}); //0 with blue edge
        q.push({0,0}); //0 with red edge
        vector<vector<bool>> vis(n,vector<bool>(2,false));
        vis[0][0]=1;
        vis[0][1]=1;
        int dis=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto[node,col]=q.front();
                q.pop();
                if(ans[node]==-1) ans[node]=dis;
                if(col==0){
                    for (int nxt:blue[node]) {
                        if (!vis[nxt][1]) {
                            vis[nxt][1]=true;
                            q.push({nxt,1});
                        }
                    }
                }
                else{
                    for (int nxt:red[node]) {
                        if (!vis[nxt][0]) {
                            vis[nxt][0]=true;
                            q.push({nxt,0});
                        }
                    }
                }
            }
            dis++;
        }
        return ans;
    }
};