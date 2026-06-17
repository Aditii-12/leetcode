class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return 0;
        sort(nums.begin(),nums.end());
        map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        for(auto &[num,cnt]:mpp){
            if(cnt==0) continue;
            for(int i=num+1;i<num+k;i++){
                if(mpp[i]<cnt) return 0;
                mpp[i]-=cnt;
            }
        }
        return 1;

    }
};