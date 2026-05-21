class Solution {
public:
    bool possible(vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost,int mid, int budget){
        int k=composition.size();
        int n=stock.size();
        for(int i=0;i<k;i++){ //iterate over machines
            long long money=0;
            for(int j=0;j<n;j++){
                long long needed=1LL*composition[i][j]*mid;
                long long ext=max(0LL,needed-stock[j]);
                money+=ext*cost[j];
            }
            if(money<=budget) return 1;
        }
        return 0;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int l=0;
        int r=1e9;
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(composition,stock,cost,mid,budget)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};