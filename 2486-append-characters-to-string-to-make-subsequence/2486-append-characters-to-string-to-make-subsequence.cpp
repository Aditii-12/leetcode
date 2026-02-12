class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.length();
        int m=t.length();
        int l=0;
        int r=0;
        while(l<n && r<m){
            if(s[l]==t[r]){
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return m-r;
    }
};