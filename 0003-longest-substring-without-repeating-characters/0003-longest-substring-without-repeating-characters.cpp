class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>mpp;
        int n=s.length();
        int l=0,r=0;
        int maxi=0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};