class Solution {
public:
int dr[4]={0,-1,1,0};
int dc[4]={-1,0,0,1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int, pair<int, int>>, //diff,row,col
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>pq;
        vector<vector<int>> dis(n,vector<int>(m,1e9)); //everything marked as infinite
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int dif=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1&&col==m-1) return dif;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr<0||nr>=n||nc<0||nc>=m) continue;
                int temp=max(abs(heights[row][col]-heights[nr][nc]),dif);
                if(temp<dis[nr][nc]){
                    dis[nr][nc]=temp;
                    pq.push({temp,{nr,nc}});
                }
            }
        }
        return 0;
    }
};