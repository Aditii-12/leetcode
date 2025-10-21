class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int nops) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());

        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;
        int mx=nums[n - 1];

        for(int i=0;i<=mx;i++) { 
            //try krenge 0 se maxnumber(jo nums me exist krra h)
            //dekhenge that we can make all the numbers to that number
            int lb = lower_bound(nums.begin(), nums.end(), i-k) - nums.begin();
            int ub = upper_bound(nums.begin(), nums.end(), i+ k) - nums.begin() - 1;

            int cnt = freq[i]+min(ub-lb+1-freq[i],nops);
            ans = max(ans, cnt);
        }

        return ans;
    }
};