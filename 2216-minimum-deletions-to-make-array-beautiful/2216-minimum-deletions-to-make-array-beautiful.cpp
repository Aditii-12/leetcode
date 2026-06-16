class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int i=0;
        while(i<n){
            while(i<n-1 && nums[i]==nums[i+1]) {
                i++;
                cnt++;
            }
            i+=2;
        }
        if((n-cnt)%2==1) cnt++;
        return cnt;
    }
};