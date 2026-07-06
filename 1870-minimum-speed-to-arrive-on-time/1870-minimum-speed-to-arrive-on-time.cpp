class Solution {
public:
    bool func(int mid,vector<int>&dist, double hour){
        double t=0;
        for(int i=0;i<dist.size()-1;i++){
            t+=ceil((double)dist[i]/mid);
        }
        t+=(double)dist[dist.size()-1]/mid;
        return t<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        if(hour<=n-1) return -1;
        int l=1;
        int h=1e7;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(mid,dist,hour)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};