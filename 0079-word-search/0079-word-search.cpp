class Solution {
public:
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,-1,1};
    bool dfs(int r,int c,int idx,vector<vector<char>>& board,string & word){
        int m=board.size();
        int n=board[0].size();
        if(idx==word.size()) return 1;
        if(r<0 || c<0 ||r>=m || c>=n) return 0;
        if(word[idx]!=board[r][c]) return 0;
        char temp=board[r][c];
        board[r][c]='#';
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(dfs(nr,nc,idx+1,board,word)) return 1;
        }
        board[r][c]=temp;
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,board,word)) return 1;
            }
        }
        return 0;
    }
};