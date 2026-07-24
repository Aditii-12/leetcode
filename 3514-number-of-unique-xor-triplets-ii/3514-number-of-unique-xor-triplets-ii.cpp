class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;
        vector<bool> pairXor(MAXX, false);
        int n = nums.size();
        for (int j = 0; j < n; j++) {
            for (int k = j; k < n; k++) {
                pairXor[nums[j] ^ nums[k]] = true;
            }
        }
        vector<bool> ans(MAXX, false);
        for (int x : nums) {
            for (int v = 0; v < MAXX; v++) {
                if (pairXor[v])
                    ans[x ^ v] = true;
            }
        }
        int cnt = 0;
        for (bool x : ans)
            cnt += x;
        return cnt;
    }
};