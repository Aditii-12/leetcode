class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({costs[i][0]-costs[i][1],i});
        }
        sort(p.begin(),p.end());
        int ans=0;
        for(int i=0;i<n/2;i++){
            int ind=p[i].second;
            ans+=costs[ind][0];
        }
        for(int i=n/2;i<n;i++){
            int ind=p[i].second;
            ans+=costs[ind][1];
        }
        return ans;
    }
};