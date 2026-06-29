class Solution {
public:
    int maxFreq(string s, int maxl, int minsz, int maxsz) {
        unordered_map<string,int>cnt;
        unordered_map<char,int>freq;
        int n=s.size();
        int i=0;
        int dis=0;
        int ans=0;
        for(int j=0;j<n;j++){
            freq[s[j]]++;
            if(freq[s[j]]==1) dis++;
            if(j-i+1>minsz){
                freq[s[i]]--;
                if(freq[s[i]]==0) dis--;
                i++;
            }
            if(j-i+1==minsz && dis<=maxl){
                string sub=s.substr(i,minsz);
                cnt[sub]++;
                ans=max(ans,cnt[sub]);
            }
        }
        return ans;
    }
};