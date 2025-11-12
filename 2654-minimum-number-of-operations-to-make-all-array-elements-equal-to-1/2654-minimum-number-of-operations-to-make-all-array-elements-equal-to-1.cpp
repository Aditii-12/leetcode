class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int f1=0; //to cehck number of 1
        for(int i=0;i<n;i++){
            if(nums[i]==1) f1++;
        }
        if(f1>0){
            return n-f1;
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=gcd(g,nums[j]); //we will continue jb tk gcd 1 na hojaye
                if(g==1){
                    mini=min(mini,j-i); //by this we will get the smalelest subarray jiska gcd 1 h
                    break;
                }
            }
        }
        //mini=min number of operations to make atleast one 1 in array
        //then n-1 operations to make everything 1
        if(mini!=INT_MAX) return mini+n-1;
        return -1;
    }
};