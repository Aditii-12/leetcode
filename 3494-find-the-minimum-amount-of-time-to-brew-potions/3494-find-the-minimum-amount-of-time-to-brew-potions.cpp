using ll=long long;
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        ll n=skill.size();
        ll m=mana.size();
        vector<ll> dp(n+1,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[j+1]=max(dp[j+1],dp[j])+1LL*mana[i]*skill[j];
            }
            for(int j=n-1;j>0;j--){
                dp[j]=dp[j+1]-1LL*mana[i]*skill[j];
            }
        }
        return dp[n];
    }
};