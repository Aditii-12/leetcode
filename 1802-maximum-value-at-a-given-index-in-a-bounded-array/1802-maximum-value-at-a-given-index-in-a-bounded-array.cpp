class Solution {
public:
    using ll=long long;
    ll get(ll mid,ll cnt){
        if(mid>cnt){
            ll last=mid-cnt;
            return (mid-1+last)*cnt/2;
        }
        return (mid-1)*mid/2+ (cnt-(mid-1));

    }
    bool func(int n,int mid,int idx,int maxs){
        ll sum=mid;
        sum+=get(mid,idx);
        sum+=get(mid,n-idx-1);
        return sum<=maxs;

    }
    int maxValue(int n, int idx, int maxs) {
        int l=1;
        int h=maxs;
        int ans=l;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(n,mid,idx,maxs)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};