class Solution {
public:
using ll=long long;
    bool func(ll mid,vector<int>& ranks,int cars){
        ll tot=0;
        for(int i=0;i<ranks.size();i++){
            tot+=(sqrt(mid/ranks[i]));
        }
        return tot>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        ll low=1;
        ll high=(ll)ranks[0]*cars*cars;
        ll ans=high;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(func(mid,ranks,cars)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};