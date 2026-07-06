class Solution {
public:
using ll=long long;
    bool func(ll mid,vector<int>&v, int tts){
        ll t=0;
        for(auto it:v){
            t+=mid/it;
            if(t>=tts) return 1;
        }
        return t>=tts;
    }
    long long minimumTime(vector<int>& time, int tts) {
        int n=time.size();
        ll l=1;
        ll h=(ll)*min_element(time.begin(),time.end())*tts;
        ll ans=h;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(func(mid,time,tts)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};