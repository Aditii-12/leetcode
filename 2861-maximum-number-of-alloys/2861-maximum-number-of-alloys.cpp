class Solution {
public:
    using ll=long long;
    bool func(int mid,vector<vector<int>>& comp,vector<int>&st, vector<int>&c, int budget){
        int k=comp.size();
        int n=comp[0].size();
        for(int i=0;i<k;i++){
            ll mon=0;
            for(int j=0;j<n;j++){
                ll needed=(ll)comp[i][j]*mid;
                ll ex=max(0LL,needed-st[j]);
                mon+=(ll)ex*c[j];
            }
            if(mon<=budget) return 1;
        }
        return 0;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int l=0;
        int h=1e9;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(mid,composition,stock,cost,budget)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};