class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char i : s) {
            if (i == '(') {
                high++;
                low++;
            } else if (i == ')') {
                high--;
                low--;
            }
            else {
                low--;
                high++;
            }
            if(high<0) return false;
            low=max(0,low);
        }
        return low==0;
    }
};