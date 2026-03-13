class Solution {
public:
    long long func(long long t,long long mid){
        //this will find how much height a worker 
        //can reduce in t time
        long long l=0,h=1e6; //bs on height that can be reduced
        while(l<=h){
            int m=l+(h-l)/2;
            long long tim=t*m*(m+1)/2;
            if(tim<=mid) l=m+1;
            else h=m-1;
        }
        return h;
    }
    long long minNumberOfSeconds(int mh, vector<int>& times) {
        int n=times.size();
        long long lo=1;
        long long hi=1e18;
        long long ans=hi;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            long long t=0;
            for(int i:times){
                t+=func(i,mid);
                if(t>=mh) break;
            }
            if(t>=mh){
                ans=mid;
                hi=mid-1;
            }
            else {
                lo=mid+1;
            }
        }
        return ans;
    }
};