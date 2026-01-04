class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>>ans;
        int n=words.size();
        sort(words.begin(),words.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(words[i][0]!=words[j][0]) continue;
                for(int k=0;k<n;k++){
                    if(i==k || j==k) continue;
                    if(words[i][3]!=words[k][0]) continue;
                    for(int p=0;p<n;p++){
                        if(i==p|| j==p ||k==p) continue;
                        if (words[p][0]!=words[j][3]) continue;
                        if (words[p][3]!=words[k][3]) continue;
                        ans.push_back({words[i],words[j],words[k],words[p]});
                    }
                }
            }
        }
        return ans;
    }
};