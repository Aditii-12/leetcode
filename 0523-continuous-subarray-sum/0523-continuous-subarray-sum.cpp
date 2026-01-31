class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1; //we r putting that we found 0 at index -1
        //so arrays starting at 0 counts
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]; //this we got prefix sum
            int mod=sum%k;
            if(mpp.find(mod)!=mpp.end()){ //already milgya
                if(i-mpp[mod]>=2) return 1;
            }
            else{
                mpp[mod]=i; //pehli br mila h
            }
        }
        return 0;
    }
};