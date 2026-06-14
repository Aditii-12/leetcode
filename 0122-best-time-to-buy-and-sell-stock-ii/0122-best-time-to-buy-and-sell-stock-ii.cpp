class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int temp=prices[i];
            while(i+1<n && prices[i+1]>prices[i]) i++;
            int temp2=prices[i];
            ans+=(temp2-temp);
        }
        return ans;
    }
};