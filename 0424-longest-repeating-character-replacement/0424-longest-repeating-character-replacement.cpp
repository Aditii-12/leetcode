class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi=0;
        int n=s.length();
        int l=0,r=0;
        int maxif=0;
        map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            maxif=max(maxif,mpp[s[r]]);
            while((r-l+1)-maxif>k){ //window size-maxif == char that needs to be replaced
                mpp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};