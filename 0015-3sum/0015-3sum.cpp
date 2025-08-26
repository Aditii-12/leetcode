class Solution {
public:
    void twosum(vector<int>& nums,int k,vector<vector<int>>& ans,int tar){
        int i=k;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]>tar)
                j--;
            else if(nums[i]+nums[j]<tar)
                i++;
            else {
                ans.push_back({-tar,nums[i],nums[j]});
                while(i<j&&nums[i]==nums[i+1]) i++;
                while(i<j&& nums[j]==nums[j-1]) j--;
                i++; 
                j--; 
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return {};
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){ //this loop is for fixing one element
        //and then aage ke bche hue me two sum lgaynege
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int tar=-nums[i];
            twosum(nums,i+1,ans,tar);
        }
        return ans;
    }
};