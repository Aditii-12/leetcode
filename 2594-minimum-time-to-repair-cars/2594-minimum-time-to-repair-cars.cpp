
class Solution {
public:
    long long repaired(vector<int>& ranks, long long mid) {
        long long count = 0;
        for (int i = 0; i < ranks.size(); i++) {
            count += sqrt(mid / ranks[i]);  // Corrected calculation
        }
        return count;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long h = (long long) *min_element(ranks.begin(), ranks.end()) * cars * cars; // Use min_element
        long long res = h;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            if (repaired(ranks, mid) >= cars) {  // Fix condition
                res = mid; // Store the best result
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};