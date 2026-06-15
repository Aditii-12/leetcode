class Solution {
public:
const int MOD=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({eff[i],speed[i]});
        }
        sort(p.rbegin(),p.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        long long ans=0;
        for(auto [e,s]:p){
            if(pq.size()==k){
                sum-=pq.top();
                pq.pop();
            }
            pq.push(s);
            sum+=s;
            ans=max(ans,sum*e);
        }
        return ans%MOD;
    }
};