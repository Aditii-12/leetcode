class Solution {
public:
int t[59];
    int solve(int n){
        if(t[n]!=-1) return t[n];
        int prod=1;
        for(int i=1;i<=n-1;i++){
            int mul=i*(max(n-i,solve(n-i)));
            prod=max(prod,mul);
        }
        return t[n]=prod;
    }
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};