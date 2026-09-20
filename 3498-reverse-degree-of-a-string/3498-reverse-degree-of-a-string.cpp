class Solution {
public:
    
    int reverseDegree(string s) {
        map<char,int>mpp;
        int i=26;
        for(char ch='a';ch<='z';ch++){
            mpp[ch]=i;
            i--;
        }
        int sum=0;
        for(int i=1;i<=s.length();i++){
            sum+=i*mpp[s[i-1]];
        }
        return sum;
    }
};