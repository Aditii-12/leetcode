class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n=s.length();
        if(n<=2) return n;
        int maxi=0;
        int l=0;
        int r=1;
        int pairs=0;
        while(r<n){
            if(s[r]==s[r-1]){
                pairs++;
            }
            while(pairs>1){
                if(s[l]==s[l+1]) pairs--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};