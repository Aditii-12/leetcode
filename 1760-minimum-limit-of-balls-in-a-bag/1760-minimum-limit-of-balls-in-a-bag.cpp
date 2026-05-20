class Solution {
public:
    bool func(vector<int>& nums, int maxop, int mid){
        int totalop=0;
        for(int num:nums){
            totalop+=num/mid;
            if(num%mid==0) totalop--;
            if(totalop>maxop) return 0;
        }
        if(totalop<=maxop) return 1;
        else return 0;
    }
    int minimumSize(vector<int>& nums, int maxop) {
        int n=nums.size();
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(func(nums,maxop,mid)) {ans=mid;
            r=mid-1;}
            else l=mid+1;
        }
        return ans;

    }
};