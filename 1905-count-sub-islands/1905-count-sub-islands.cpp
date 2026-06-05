class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& g1,vector<vector<int>>& g2){
        int n=g1.size();
        int m=g1[0].size();
        if(r<0 || c<0 || r>=n||c>=m) return 1;
        if(g2[r][c]==0) return 1;
        g2[r][c]=0;
        bool f=(g1[r][c]==1);
        bool up=dfs(r-1,c,g1,g2);
        bool down=dfs(r+1,c,g1,g2);
        bool le=dfs(r,c-1,g1,g2);
        bool ri=dfs(r,c+1,g1,g2);
        return f && up && down && le && ri; 
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2)) ans++;
                }
            }
        }
        return ans;
    }
};