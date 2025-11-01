#define ll long long
class Solution {
public:
    bool func(ll mid,vector<int>&time,ll tt){
        ll total=0; //total trips
        for(int i=0;i<time.size();i++){
            total+=mid/time[i];
            if(total>=tt) return 1;
        }
        return 0;
    }
    long long minimumTime(vector<int>& time, int tt) {
        ll n=time.size();
        ll l=1;
        ll h=(ll) *min_element(time.begin(),time.end())*tt;
        ll ans=h;
        while(l<=h){
            ll m=l+(h-l)/2;
            if(func(m,time,tt)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};