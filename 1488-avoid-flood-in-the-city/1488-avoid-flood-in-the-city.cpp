class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> f; // jo lake lsst fill kri h vo
        set<int> d;                // yha dry days jo available h

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                int lake = rains[i];
                ans[i] = -1; // raining day we cant do anything so we mark as -1
                if (f.count(lake)) { // this lake already had water before
                    auto it = d.upper_bound(
                        f[lake]); // find a dry day after last fill
                    if (it == d.end())
                        return {};   // no dry day available → flood
                    ans[*it] = lake; // dry this lake on that dry day
                    d.erase(it);     // remove used dry day
                }
                f[lake] = i; // update last fill day for this lake
            } else {
                d.insert(i);
            }
        }
        return ans;
    }
};