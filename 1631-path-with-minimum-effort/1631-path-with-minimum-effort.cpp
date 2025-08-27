class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, //diff,row,col
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,1e9)); //everything marked as infinite
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={0,-1,1,0};
        int dc[]={-1,0,0,1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int effort=max(abs(heights[row][col]-heights[nr][nc]),diff);
                    if(effort<dis[nr][nc]){
                        dis[nr][nc]=effort;
                        pq.push({effort,{nr,nc}});
                    }
                }
            }

        }
        return 0; 
    }
};