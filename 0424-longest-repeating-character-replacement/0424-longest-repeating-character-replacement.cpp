class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0,r=0;
        int ans=0;
        int maxf=0;
        map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            while((r-l+1)-maxf>k){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};