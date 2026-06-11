class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        sort(sources.begin(),sources.end(),[](auto &a,auto &b){
            return a[2]>b[2];
        });
        vector<vector<int>>grid(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(auto it:sources){
            q.push({it[0],it[1]});
            grid[it[0]][it[1]]=it[2];
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                if(grid[nr][nc]!=0) continue;
                grid[nr][nc]=grid[r][c];
                q.push({nr,nc});
            }
        }
        return grid;

    }
};