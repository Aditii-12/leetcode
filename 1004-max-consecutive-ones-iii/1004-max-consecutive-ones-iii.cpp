class Solution {
public:
//we will find longest window with <=k zeros to un sbko flip krke 1 krdenge
    int longestOnes(vector<int>& s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int cnt=0;
        int maxi=0;
        while(r<n){
            if(s[r]==0) cnt++;
            while(cnt>k){
                if(s[l]==0) cnt--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
        
    }
};