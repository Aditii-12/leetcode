class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>r(n,INT_MIN);
        vector<int>c(n,INT_MIN);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i]=max(r[i],grid[i][j]);
                c[i]=max(c[i],grid[j][i]);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp=min(r[i],c[j]);
                if(grid[i][j]<temp) sum+=(temp-grid[i][j]);
            }
        }
        return sum;
    }
};