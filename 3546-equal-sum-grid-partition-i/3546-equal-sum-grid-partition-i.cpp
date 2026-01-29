using ll=long long;
class Solution {
public:
    static bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<ll> prer(n,0); //prefix row wise
        vector<ll> prec(m,0); //prefix column wise
        //basically prer[0] will contain pura sum of 0th row
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ll v=grid[i][j];
                prer[i]+=v;
                prec[j]+=v;
            }
        }

        ll ts=0;
        for (ll r:prer)
            ts+=r;

        //horizontal cut check
        ll curr = 0;
        for (int i=0;i<n-1;i++) {
            curr+=prer[i];
            ll rem=ts-curr; 
            if (curr==rem)
                return true;
        }

        //vertical cut
        ll currc = 0;
        for (int j=0;j<m-1;j++) {
            currc+=prec[j];
            ll remc=ts-currc;
            if (currc==remc)
                return true;
        }
        return false;
    }
};
