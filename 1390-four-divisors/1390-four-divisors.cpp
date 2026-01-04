class Solution {
public:
//2 cases
//1,p,p^2,p^3 type of format
//then 1,p,q,p*q
    bool isp(int x){
        if(x<2) return 0;
        for(int i=2;i*i<=x;i++)
            if(x%i==0) return 0;
        return 1;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            int p=round(cbrt(x)); //to check case 1
            if(1LL*p*p*p==x && isp(p)){
                ans+=(1+p+p*p+x);
                continue;
            }
            //to check case 2
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    int a=i;
                    int b=x/i;
                    if(a!=b && isp(a) && isp(b)) {
                        ans+=(1+a+b+a*b);
                    }
                    break;
                }
            }

        }
        return ans;
    }
};