class Solution {
public:
using ll=long long;
    int uniqueLetterString(string s) {
        int n=s.length();
        vector<vector<int>>pos(26);
        for(int i=0;i<n;i++){
            pos[s[i]-'A'].push_back(i);
        }
        long long ans=0;
        for(int i=0;i<26;i++){
            vector<int>v;
            v.push_back(-1);
            for(int x:pos[i]) v.push_back(x);
            v.push_back(n);
            for(int j=1;j<v.size()-1;j++){
                ll left=v[j]-v[j-1];
                ll rig=v[j+1]-v[j];
                ans+=left*rig;
            }
        }
        return ans;
    }
};