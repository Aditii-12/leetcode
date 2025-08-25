class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s(nums1.begin(),nums1.end());
        vector<int>ans;
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end()) {ans.push_back(nums2[i]);
            s.erase(nums2[i]);}
        }
        return ans;
    }
};