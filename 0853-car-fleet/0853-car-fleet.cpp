class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n=pos.size();
        vector<pair<int,int>>c;
        for(int i=0;i<n;i++){
            c.push_back({pos[i],speed[i]});
        }
        sort(c.begin(),c.end());
        int fleet=0;
        double lastt=0;
        for(int i=n-1;i>=0;i--){
            double currt=(double)(target-c[i].first)/c[i].second;
            if(currt>lastt){
                fleet++;
                lastt=currt;
            }
        }
        return fleet;
    }
};