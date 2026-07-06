class Solution {
public:
    using ll=long long;
    bool func(ll mid,vector<int>& ranks,int car){
        ll t=0;
        for(auto it:ranks){
            t+=(sqrt(mid/it));
        }
        return t>=car;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        ll l=1;
        ll h=(ll)*min_element(ranks.begin(),ranks.end())*cars*cars;
        ll ans=h;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(func(mid,ranks,cars)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;

    }
};