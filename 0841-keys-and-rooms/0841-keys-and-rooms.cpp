class Solution {
public:
    void dfs(int room,vector<vector<int>>& rooms,vector<bool>& vis){
        vis[room]=1;
        for(auto it:rooms[room]){
            if(!vis[it]){
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,0);
        dfs(0,rooms,vis);
        for(int i=0;i<n;i++){
            if(!vis[i]) return 0;
        }
        return 1;
    }
};