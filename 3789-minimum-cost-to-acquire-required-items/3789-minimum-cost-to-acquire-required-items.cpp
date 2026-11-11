class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1,
                          int n2) {
        long long tot=0;
        if (c1+c2<=cb){
            tot=1LL*c1*n1+1LL*c2*n2;
        } else {
            int cnt_3 = min(n1,n2);
            tot=1LL * cnt_3 * cb;
            n1-= cnt_3;
            n2-= cnt_3;
            if (n1> 0) {
                tot+=1LL *n1* min(c1,cb);
            }
            else if (n2>0) {
                tot+=1LL*n2*min(c2,cb);
            }
        }
        return tot;
    }
};