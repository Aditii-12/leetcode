class Solution {
public:
    bool func(int mid,vector<int>& piles, int h){
        int n=piles.size();
        long long hours=0;
        for(int i=0;i<n;i++){
            hours+=ceil((double)piles[i]/mid);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(func(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};