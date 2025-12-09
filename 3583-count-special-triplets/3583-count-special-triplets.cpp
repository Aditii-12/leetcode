class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        unordered_map<int,int>s;
        unordered_map<int,int>p;
        for(auto it:nums) s[it]++; //sare numbers pehle suffix me daldiye
        long long ans=0;
        for(auto it:nums){
            s[it]--;
            ans+=(long long)p[2*it] * s[2*it];
            p[it]++;
        }
        return ans%mod;
    }
};