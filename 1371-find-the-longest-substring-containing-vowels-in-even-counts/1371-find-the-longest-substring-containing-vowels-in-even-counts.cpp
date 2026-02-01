class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n=s.length();
        unordered_map<int,int>mpp; //we store the first index
        int mask=0; //all vowels are even sbse phle
        int ans=0; 
        mpp[0]=-1; //we r storing index ab
        for(int i=0;i<n;i++){
            if(s[i]=='a') mask^=(1<<0);
            else if(s[i]=='e') mask^=(1<<1);
            else if(s[i]=='i') mask^=(1<<2);
            else if(s[i]=='o') mask^=(1<<3);
            else if(s[i]=='u') mask^=(1<<4);
            if(mpp.find(mask)!=mpp.end()){
                ans=max(ans,i-mpp[mask]);
            }
            else mpp[mask]=i; //first occurence
        }
        return ans;
    }
};