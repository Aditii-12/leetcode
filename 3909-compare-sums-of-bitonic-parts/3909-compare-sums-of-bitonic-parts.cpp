class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i+1<n && nums[i]<nums[i+1]) i++;
        long long s1=accumulate(nums.begin(),nums.begin()+i+1,0LL);
        long long s2=accumulate(nums.begin()+i,nums.end(),0LL);
        if(s1>s2) return 0;
        else if(s1<s2) return 1;
        return -1;
    }
};