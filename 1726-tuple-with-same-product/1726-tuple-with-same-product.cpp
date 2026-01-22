class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mpp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto &it:mpp){
            if(it.second>=2){
                ans+=(it.second)*(it.second-1)*4; //nc2*8
            }
        }
        return ans;
    }
};