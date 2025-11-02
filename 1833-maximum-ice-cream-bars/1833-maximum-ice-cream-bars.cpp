class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int n=costs.size();
        int i=0;
        int j=n-1;
        int count=0;
        while(i<=j){
            if(costs[i]<=coins){
                count++;
                coins-=costs[i];
            }
            else break;
            i++;
        }
        return count;
    }
};