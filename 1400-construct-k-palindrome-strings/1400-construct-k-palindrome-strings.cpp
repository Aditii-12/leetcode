class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        vector<int>fr(26,0);
        int cnt=0;
        for(auto it:s){
            fr[it-'a']++;
        }
        for(auto it:fr){
            if(it%2==1) cnt++;
        }
        return (cnt<=k && k<=n);

    }
};