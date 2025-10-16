class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int n) {
        vector<int>mpp(n);
        for(auto x:nums) {
            int temp=(x%n+n)%n;
            mpp[temp]++;
        }
        int m=0;
        while(mpp[m%n]>0){
            mpp[m%n]--;
            m++;
        }
        return m;
        
    }
};