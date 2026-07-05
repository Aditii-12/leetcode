class Solution {
public:
    bool func(vector<int>& candies,long long k,int mid){
        long long c=0;
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
            if(func(candies,k,m)) 
            {
                ans=m;
                l=m+1;
            }
            else h=m-1;
        }
        return ans;
    }
};