class Solution {
public:
    int brokenCalc(int s, int target) {
        int ops = 0;
        while (target>s) {
            if (target%2==0) {
                target/=2;
            } else {
                target+=1;
            }
            ops++;
        }
        return ops+(s-target);
    }
};