class Solution {
public:
    using ll=long long;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll>deg(n,0);
        for(auto it:roads){
            deg[it[0]]++;
            deg[it[1]]++;
        }
        sort(deg.rbegin(),deg.rend());
        ll ans=0;
        int j=0;
        for(int i=n;i>0;i--) ans+=(deg[j++]*i);
        return ans;
    }
};