class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;
        int i=0;
        for(auto it:points){
            pq.push({it[0]*it[0]+it[1]*it[1],i});
            if(pq.size()>k) pq.pop();
            i++;
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto [dis,ind]=pq.top();
            int x=points[ind][0];
            int y=points[ind][1];
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};