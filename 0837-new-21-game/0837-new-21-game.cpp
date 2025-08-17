class Solution {
public:
    double new21Game(int n, int k, int maxp) {
        if(k==0||n>=k+maxp) return 1.0;
        vector<double>t(n+1,0.0);
        t[0]=1.0;
        double sum=1.0,res=0.0;
        for(int i=1;i<=n;i++){
            t[i]=sum/maxp;
            if(i<k) sum+=t[i];
            else res+=t[i];
            if(i-maxp>=0) sum-=t[i-maxp];
        }
        return res;
    }
};