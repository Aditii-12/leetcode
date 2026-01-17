class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0)); //n*n matrix me 0 bhr diya
        for(auto &it:queries){
            int r1=it[0];
            int c1=it[1];
            int r2=it[2];
            int c2=it[3];
            for(int i=r1;i<=r2;i++){
                ans[i][c1]+=1;
                if(c2+1<n)
                    ans[i][c2+1]--;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                ans[i][j]+=ans[i][j-1];
            }
        }
        return ans;
    }
};