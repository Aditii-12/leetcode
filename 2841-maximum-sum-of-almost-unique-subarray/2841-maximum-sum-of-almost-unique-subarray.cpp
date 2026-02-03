class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        long long maxi=0;
        long long sum=0;
        unordered_map<int,int>freq;
        int l=0;
        int r=0;
        while(r<n){
            sum+=nums[r];
            freq[nums[r]]++;
            if(r-l+1>k){ //to keep window size k
                sum-=nums[l];
                freq[nums[l]]--;
                if(freq[nums[l]]==0) freq.erase(nums[l]);
                l++;
            }
            if(r-l+1==k){
                if(freq.size()>=m) maxi=max(maxi,sum);
            }
            r++;
        }
        return maxi;
    }
};