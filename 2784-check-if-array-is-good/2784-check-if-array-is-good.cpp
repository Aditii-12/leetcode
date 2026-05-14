class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        bitset<201>seen;
        bool dup=0;

        for (auto& num:nums) {
            if (num>n) return 0;

            if (seen.test(num)) {
                if (num<n||dup) return 0;
                dup |= 1;
                continue;
            }
            seen.set(num);
        }

        return true;
    }
};