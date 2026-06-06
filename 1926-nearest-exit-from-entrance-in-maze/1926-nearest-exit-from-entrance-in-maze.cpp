class Solution {
public:
    int dr[4]={0,0,-1,1};
    int dc[4]={1,-1,0,0};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [r,c]=q.front();
                q.pop();
                if((r==0||c==0||r==n-1||c==m-1)&&!(r==entrance[0] && c==entrance[1]))
                    return steps;
                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                    if(maze[nr][nc]=='+') continue;
                    maze[nr][nc]='+';
                    q.push({nr,nc});
                }
            }
            steps++;
        }
        return -1;
    }
};