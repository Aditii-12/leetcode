class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.length();
        map<char,int>mpp;
        int l=0,r=0;
        int ans=0,maxf=0;
        while(r<n){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            while((r-l+1)- maxf>k){
                mpp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};