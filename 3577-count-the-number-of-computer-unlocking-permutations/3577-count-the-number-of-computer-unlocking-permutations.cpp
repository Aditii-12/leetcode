class Solution {
public:
    int countPermutations(vector<int>& com) {
        int mod=1e9+7;
        int n=com.size();
        if(*min_element(com.begin()+1,com.end())<=com[0]) return 0;
        int ans=1;
        for(int i=2;i<n;i++){
            ans=(long long)ans*i%mod;
        }
        return ans;
    }
};