class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    void dfs(int r,int c,vector<vector<char>>& grid){
        int m=grid.size();
        int n=grid[0].size();
        if(r<0||c<0||r>=m||c>=n) return;
        if(grid[r][c]!='O') return;
        grid[r][c]='a';
        for(int i=0;i<4;i++){
            dfs(r+dr[i],c+dc[i],grid);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][n-1]=='O') dfs(i,n-1,board);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(0,i,board);
            if(board[m-1][i]=='O') dfs(m-1,i,board);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='a') board[i][j]='O';
            }
        }
    }
};