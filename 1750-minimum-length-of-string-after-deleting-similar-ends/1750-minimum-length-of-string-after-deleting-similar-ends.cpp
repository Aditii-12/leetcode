class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<j ){
            if(s[i]!=s[j]) return j-i+1;
            char ch=s[i];
            while(i<=j && s[i]==ch) i++;
            while(i<=j && s[j]==ch) j--;
        }
        return j-i+1;
    }
};