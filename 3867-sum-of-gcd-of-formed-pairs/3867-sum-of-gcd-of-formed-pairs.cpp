class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        vector<int>t(n);
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            t[i]=gcd(maxi,nums[i]);
        }
        sort(t.begin(),t.end());
        long long sum=0;
        int i=0;
        int j=n-1;
        while(i<j){
            sum+=gcd(t[i],t[j]);
            i++;
            j--;
        }
        return sum;
    }
};