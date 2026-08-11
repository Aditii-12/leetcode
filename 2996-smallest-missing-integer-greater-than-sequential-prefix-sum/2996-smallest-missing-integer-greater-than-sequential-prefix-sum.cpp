class Solution {
public:
    int missingInteger(std::vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> num_set(nums.begin(),nums.end());
        int t=nums[0];
        for (int i=1;i<n;i++) {
            if (nums[i]==nums[i-1]+1) {
                t+=nums[i];
            } else {
                break;
            }
        }
        while (num_set.count(t)) {
            t+=1;
        }
        return t;
    }
};