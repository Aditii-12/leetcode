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
        int h=*max_element(nums.begin(),nums.end());
        int ans=h;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(nums,maxop,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};