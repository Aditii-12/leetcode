class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(discounts.rbegin(),discounts.rend());
        sort(prices.rbegin(),prices.rend());
        double ans=0;
        int i=0;
        for(i=0;i<min(prices.size(),discounts.size());i++){
            ans+=(double)(prices[i])*(100-discounts[i])/100;
        }
        while(i<prices.size()){
            ans+=prices[i];
            i++;
        }
        return ans;
    }
};