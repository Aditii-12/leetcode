class Solution {
public:
    bool isPowerOfFour(int n) {
      return n>0 && (n&(n-1))==0&&(n-1)%3==0;
      //(n&(n-1)) ==1 to check if it is power of 2
      //n-1%3 to check divisible by power of 4
    }
};