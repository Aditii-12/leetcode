class Solution {
public:
    int maxScore(vector<int>& ca, int k) {
      int n=ca.size();
      int lsum=0,rsum=0;
      int r=n-1;
      for(int i=0;i<k;i++){
        lsum+=ca[i];
      }
      int msum=lsum;
      for(int i=k-1;i>=0;i--){
        lsum-=ca[i];
        rsum+=ca[r];
        r--;
        msum=max(msum,lsum+rsum);
      }
      return msum;

    }
};