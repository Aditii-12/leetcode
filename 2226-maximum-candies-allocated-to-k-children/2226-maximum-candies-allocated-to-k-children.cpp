class Solution {
public:
    bool func(vector<int>& candies,long long k,int mid){
        long long c=0;
        //we will see kitne bcho me we can distribute mid candies
        //in the dekhlenge c>=n or not
        for(int i=0;i<candies.size();i++){
            c+=candies[i]/mid;
        }
        return c>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int ans=0;
        int l=1;
        int h=*max_element(candies.begin(),candies.end());
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(candies,k,m)) //possible h m candies baatna among k bche
            {
                ans=m;
                l=m+1; //now zada candies baatkr dekhenge
            }
            else h=m-1;
        }
        return ans;
    }
};