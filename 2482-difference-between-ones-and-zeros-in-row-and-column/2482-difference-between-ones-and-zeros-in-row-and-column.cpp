class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>r(m,0); //ones in a r
        vector<int>c(n,0);
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                r[i]+=grid[i][j];
                c[j]+=grid[i][j];
            }
        }
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                grid[i][j]=2*(r[i]+c[j])-m-n;
            }
        }
        return grid;
    }
};