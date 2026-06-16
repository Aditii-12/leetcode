class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        int r=0;
        int ans=0;
        int i=0;
        while(r<target){
            if(i<n && coins[i]<=r+1){
                r+=coins[i];
                i++;
            }
            else{
                ans++;
                r+=(r+1);
            }
        }
        return ans;
    }
};