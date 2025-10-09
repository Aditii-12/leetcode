class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string output;
        int l = 0, r = 0;
        while (l < s.length()) {
            if (r < spaces.size() && l == spaces[r]) {
                output+=" ";
                output +=s[l];
                
                r++;
            } else
                output += s[l];
            l++;
        }
        return output;
    }
};