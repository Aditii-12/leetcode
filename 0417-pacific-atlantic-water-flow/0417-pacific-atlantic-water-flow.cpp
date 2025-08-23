class Solution {
public:
int n,m;
int dr[4]={0,0,-1,1};
int dc[4]={-1,1,0,0};
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>&vis,int row,int col){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr<0||nr>=n||nc>=m||nc<0||vis[nr][nc]==1) continue;
            if(heights[nr][nc]>=heights[row][col]){
                dfs(heights,vis,nr,nc);
            }
        }

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,0));
        vector<vector<bool>>atl(n,vector<bool>(m,0));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            //first and last row
            dfs(heights,pac,i,0); //i,j(row,col);
            dfs(heights,atl,i,m-1); 
        }
        for(int i=0;i<m;i++){
            //first and last column
            dfs(heights,pac,0,i);
            dfs(heights,atl,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]==1 && atl[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};