class Solution {
public:
int n,m;
int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nc>=0 && nr>=0 && nr<n && nc<m && vis[nr][nc]==0 && board[nr][nc]=='O'){
                //ab ye visited mark krdiya which is
                //we cant change this to x 
                //jb hm end me sare 0(andr wale jo boundary se connected ni h) unko x krenge
                //tb inko ni krenge
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
         n=board.size();
        m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        // traversing for first and last row
        //upr ki last ki line
        //m is no of columns 
        for(int i=0;i<m;i++){
            if(vis[0][i]!=1 && board[0][i]=='O') 
                dfs(0,i,board,vis);
            if(vis[n-1][i]==0 && board[n-1][i]=='O')
                dfs(n-1,i,board,vis);
        }
        //for side ki 2 line. extremee columns
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
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