class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(128, 0);
            for (int j = i; j < n; j++) {
                freq[s[j]]++;
                int maxf = INT_MIN, minf = INT_MAX;
                for (int k = 0; k < 128; k++) {
                    if (freq[k] > 0) { // Ignore characters that are not present
                        maxf = max(maxf, freq[k]);
                        minf = min(minf, freq[k]);
                    }
                }
                
                beauty += (maxf - minf);
            }
        }
        return beauty;
    }
};