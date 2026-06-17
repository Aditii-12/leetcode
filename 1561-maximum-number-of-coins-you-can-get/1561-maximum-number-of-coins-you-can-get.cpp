class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        n/=3;
        sort(piles.rbegin(),piles.rend());
        int i=1;
        int ans=0;
        int cnt=0;
        while(cnt<n){
            ans+=piles[i];
            i+=2;
            cnt++;
        }
        return ans;
    }
};