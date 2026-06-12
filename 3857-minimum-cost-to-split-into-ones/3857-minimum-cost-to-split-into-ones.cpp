class Solution {
public:
    int minCost(int n) {
        if(n==1) return 0;
        n--;
        int sum=0;
        while(n>=1){
            sum+=n;
            n--;
        }
        return sum;
    }
};