class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                bool f=1;
                for(auto k:mpp){
                    if(k.second!=mpp[s[j]]){
                        f=0;
                        break;
                    }
                }
                if(f) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};