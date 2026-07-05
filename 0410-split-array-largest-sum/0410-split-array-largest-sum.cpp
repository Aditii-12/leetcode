class Solution {
public:
    bool func(vector<int>& nums,int k,long long mid){
        int cnt=1;
        long long sum=0;
        for(int x:nums){
            if(sum+x>mid){
                cnt++;
                sum=x;
            }
            else{
                sum+=x;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long l=*max_element(nums.begin(),nums.end());
        long long h=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=h;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(func(nums,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};