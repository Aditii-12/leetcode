class Solution {
public:
    long long appealSum(string s) {
        int n=s.size();
        vector<vector<int>>pos(26);
        for(int i=0;i<n;i++){
            pos[s[i]-'a'].push_back(i);
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            vector<int>v;
            v.push_back(-1);
            for(auto idx:pos[i]) v.push_back(idx);
            v.push_back(n);
            for(int j=1;j<v.size();j++){
                long long left=v[j]-v[j-1];
                long long right=n-v[j];
                ans+=left*right;
            }
        }
        return ans;
    }
};