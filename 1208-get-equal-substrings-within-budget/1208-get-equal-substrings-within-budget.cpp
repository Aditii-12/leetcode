class Solution {
public:
    int equalSubstring(string s, string t, int maxcost) {
        int n=s.length();
        vector<int>c;
        for(int i=0;i<n;i++){
            c.push_back(abs(s[i]-t[i]));
        }
        int maxi=0;
        int sum=0;
        int l=0;
        int r=0;
        while(r<n){
            sum+=c[r];
            while(sum>maxcost){
                sum-=c[l];
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};