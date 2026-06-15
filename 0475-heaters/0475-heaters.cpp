class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans=0;
        for(auto h:houses){
            auto it=lower_bound(heaters.begin(),heaters.end(),h);
            int ri=INT_MAX;
            int le=INT_MAX;
            if(it!=heaters.end()){
                ri=*it-h;
            }
            if(it!=heaters.begin()){
                le=h-*prev(it);
            }
            int near=min(ri,le);
            ans=max(ans,near);
        }
        return ans;
    }
};