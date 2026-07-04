class Solution {
public:
    bool func(int m,vector<int>& piles,int thr){
        int n=piles.size();
        long long h=0;
        for(int i=0;i<n;i++){
            if(piles[i]%m==0) h+=piles[i]/m;
            else h+=(piles[i]/m)+1;
            if(h>thr) return 0;
        }
        return h<=thr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=hi){
            int m=l+(hi-l)/2;
            if(func(m,piles,h)){
                ans=m;
                hi=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};