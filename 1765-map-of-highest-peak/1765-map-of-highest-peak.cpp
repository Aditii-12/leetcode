class Solution {
public:
    int dr[4]={0,0,1,-1};
    int dc[4]={1,-1,0,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& iswater) {
        int m=iswater.size();
        int n=iswater[0].size();
        vector<vector<int>>ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(iswater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
                if(ans[nr][nc]!=-1) continue;
                ans[nr][nc]=ans[r][c]+1;
                q.push({nr,nc}); 
            }
        }
        return ans;
    }
};