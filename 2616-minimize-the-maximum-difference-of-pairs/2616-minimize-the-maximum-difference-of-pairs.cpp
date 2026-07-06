class Solution {
public:
    bool func(int m,vector<int>&nums,int p){
        int i=0;
        int pairs=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=m){
                pairs++;
                i+=2;
            }
            else i++;
        }
        return pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int h=nums[n-1]-nums[0];
        int ans=INT_MAX;
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(m,nums,p)){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};