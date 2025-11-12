class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        unordered_set<int>st;
        st.insert(0);
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int temp=q.front();
                q.pop();
                for(auto it:rooms[temp]){
                    if(!st.count(it)){
                    st.insert(it);
                    q.push(it);
                    }
                }
            }
        }
        if(st.size()==n) return 1;
        return 0;
    }
};