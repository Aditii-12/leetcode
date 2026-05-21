class Solution {
public:
    int func(vector<int>& arr,int mid){
        int sum=0;
        for(auto it:arr){
            if(it<=mid) sum+=it;
            else sum+=mid;
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0;
        int r=*max_element(arr.begin(),arr.end());
        int ans=r;
        int bdiff=INT_MAX; //best diff
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=func(arr,mid);
            int diff=abs(sum-target);
            if(diff<bdiff){
                bdiff=diff;
                ans=mid;
            }
            else if(diff==bdiff){
                ans=min(ans,mid);
            }
            if(sum<target) l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};