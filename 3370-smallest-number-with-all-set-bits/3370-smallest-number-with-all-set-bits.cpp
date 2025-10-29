class Solution {
public:
    int smallestNumber(int n) {
        int tmp=1;
        while (tmp<n)
            tmp=tmp*2+1;
        return tmp;
    }
};