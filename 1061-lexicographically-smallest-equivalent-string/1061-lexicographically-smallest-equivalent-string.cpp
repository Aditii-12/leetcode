class Solution {
public:
    map<char, char> mpp;

    // Find function to get the smallest equivalent character
    char find(char x) {
        if (mpp[x] != x)
            mpp[x] = find(mpp[x]);  
        return mpp[x];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Initialize each character to itself
        for (char c = 'a'; c <= 'z'; c++) {
            mpp[c] = c;
        }

        // Union step: merge the equivalence classes
        for (int i = 0; i < s1.length(); i++) {
            char a = find(s1[i]);
            char b = find(s2[i]);
            if (a == b) continue;
            if (a < b) mpp[b] = a;
            else mpp[a] = b;
        }
        for (int i = 0; i < baseStr.length(); i++) {
            baseStr[i] = find(baseStr[i]);
        }

        return baseStr;
    }
};
