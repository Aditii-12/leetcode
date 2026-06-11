class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        int o=0;
        for(auto it:nums1){
            if(it%2==1){
                o++;
                mini=min(mini,it);
            }
        }
        if(o==0) return 1;
        for(auto it:nums1){
            if(it%2==0 && mini>it) return 0;
        }
        return 1;
    }
};