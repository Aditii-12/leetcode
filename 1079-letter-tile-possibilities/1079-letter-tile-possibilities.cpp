class Solution {
public:
    int dfs(vector<int>&freq){
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            freq[i]--;
            ans++;
            ans+=dfs(freq);
            freq[i]++;
        }
        return ans;
    }
    int numTilePossibilities(string tiles) {
        vector<int>freq(26);
        for(char ch:tiles){
            freq[ch-'A']++;
        }
        return dfs(freq);
    }
};