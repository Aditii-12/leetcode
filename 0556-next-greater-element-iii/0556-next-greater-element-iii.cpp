class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int sz=s.length();
        int i=sz-1;
        while(i>0 && s[i-1]>=s[i]) i--;
        if(i==0) return -1;
        i--;
        int j=sz-1;
        while(s[j]<=s[i]) j--;
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());
        long long ans=stoll(s);
        if(ans>INT_MAX) return -1;
        return ans;
    }
};