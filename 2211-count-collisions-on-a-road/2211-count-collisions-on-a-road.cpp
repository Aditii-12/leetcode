class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int i = 0, j = n - 1;

        //sytarting ke sare l htadenghe
        while (i<n&& directions[i]=='L') i++;

        //end ke sare r
        while (j>=0 && directions[j]=='R') j--;

        int ans=0;
        //bich me jitne l and r bche h sare 1 se bdhayenge
        //agr 2 b collide krenge to dono ka 1 1 count hoga
        //which will be 2
        //S ka we will not count
        for (int k=i;k<=j;k++) {
            if (directions[k]=='L'||directions[k] == 'R')
                ans++;
        }
        
        return ans;
    }
};
