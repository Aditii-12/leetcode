class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int ans=0;
        //ya to boat horizontally start hori h ya to vertically
        //and no 2 boats touch each other
        //to hm bs top cell hi count krenge
        //agr if we are in cell jo x h and agr uske upr already x h 
        //to we already counted that
        //and for column if left wala cell already X h to already counted so continue
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (board[i][j]=='.') continue;

                if (i>0 && board[i-1][j]=='X')
                    continue;

                if (j>0 && board[i][j-1]=='X')
                    continue;
                ans++;
            }
        }
        return ans;
    }
};