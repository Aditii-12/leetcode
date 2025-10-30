class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board){
        int n=board.size();
        int m=board[0].size();
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(ncol<m && nrow<n && nrow>=0 && ncol>=0 && board[nrow][ncol] == 'O'&&vis[nrow][ncol]==0){
                dfs(nrow,ncol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        //first row & last row traversing
        for(int i=0;i<m;i++){
            if(vis[0][i]==0 && board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(vis[n-1][i]==0 && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
        // first and last col
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
       
    }
};