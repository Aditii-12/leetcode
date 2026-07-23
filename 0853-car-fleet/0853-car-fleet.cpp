class Solution {
public:
    int carFleet(int tar, vector<int>& pos, vector<int>& sp) {
        int n=pos.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({pos[i],sp[i]});
        }
        sort(v.begin(),v.end());
        int cnt=0;
        double last=0;
        for(int i=n-1;i>=0;i--){
            double curr=(double)(tar-v[i].first)/v[i].second;
            if(curr>last) {
                cnt++;
                last=curr;
            }
        }
        return cnt;
    }
};