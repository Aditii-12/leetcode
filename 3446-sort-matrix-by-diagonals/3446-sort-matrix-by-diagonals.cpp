class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,priority_queue<int>> maxh; 
        //maxh for uppper right corner
        //jha descending order me krna ho
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>minh;
        //minh for bottom left corner
        //jha ascending order me arrange krna h
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int f=i-j;
                if(f<0) minh[f].push(grid[i][j]);
                else maxh[f].push(grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int f=i-j;
                if(f<0) {
                    grid[i][j]=minh[f].top();
                    minh[f].pop();
                }
                else{
                    grid[i][j]=maxh[f].top();
                    maxh[f].pop();
                }
            }
        }
    return grid;
    }
};