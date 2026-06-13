class Solution {
public:
bool isprime(int n){
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(i%2==0){
                if(isprime(x)) continue;
                while(!isprime(x)){
                    ans++;
                    x++;
                }
            }
            else{
                if(!isprime(x)) continue;
                while(isprime(x)){
                    x++;
                    ans++;
                }
            }
        }
        return ans;
    }
};