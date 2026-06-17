class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rcnt=0;
        int ccnt=0;
        for(int i=0;i<n;i++){
            int l=0; int r=m-1;
            while(l<r){
                if(grid[i][l]!=grid[i][r]) rcnt++;
                l++;
                r--;
            }
        }
        for(int i=0;i<m;i++){
            int l=0;
            int r=n-1;
            while(l<r){
                if(grid[l][i]!=grid[r][i]) ccnt++;
                l++;
                r--;
            }
        }
        return min(rcnt,ccnt);
    }
};