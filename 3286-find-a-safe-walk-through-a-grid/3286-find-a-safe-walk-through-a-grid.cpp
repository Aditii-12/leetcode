class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
        bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>>q;
        //health,row,col
        vector<vector<int>>vis(n,vector<int>(m,0));
        if(grid[0][0]==1){
            q.push({health-1,{0,0}});
        }
        else{
        q.push({health,{0,0}});
        }
        vis[0][0]=1;
        while(!q.empty()){
            int val=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            if(row==n-1 && col==m-1){
                if(val>=1) return 1;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nc>=0 && nc<m && nr<n && !vis[nr][nc]){
                    if(grid[nr][nc]==0) q.push({val,{nr,nc}});
                    else q.push({val-1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        return 0;
    }
};