class Solution {
public:
using ll = long long;
const int P=int(1e9)+7;
    int countHomogenous(string s) {
        ll n=s.length();
        ll l=0,r=0;
        ll ans=0;
        ll temp=0;
        while(r<n){
            while(r<n&& s[r]==s[l]){
                r++;
            }
            long long len=r-l;
            ans+=len*(len+1)/2;
            l=r;
        }
        return ans;
    }
};