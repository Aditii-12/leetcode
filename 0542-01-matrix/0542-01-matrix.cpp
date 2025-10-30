class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int drow[]={-1,0,0,1};
        int dcol[]={0,-1,1,0};
        vector<vector<int>> result(n,vector<int>(m,0));
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        //for all zeros first(shortest dist of 0 from 0 is 0 only)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j]=1; //in visited 1 means that we visited that block already
                    q.push({i,j});
                }
            }
        }
        //ab hm har 0 se bfs krenge, so if visited is not 1, it means it is "1"
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0) //visited=0 means its not zero that means distance have to calculated.
                {
                    result[nrow][ncol]=result[row][col]+1;
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        
        
    }
    return result;
    }
};