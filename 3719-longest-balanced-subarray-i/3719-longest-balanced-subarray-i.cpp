class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_set<int>e,o;
        for(int i=0;i<n;i++){
            e.clear();
            o.clear();
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) e.insert(nums[j]);
                else o.insert(nums[j]);
                if(e.size()==o.size()) maxi=max(maxi,j-i+1);
            }
        }
        return maxi;

    }
};