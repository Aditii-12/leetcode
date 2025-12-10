class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=0;
        int j=0;
        vector<int>dono;
        while(l<nums1.size()&&j<nums2.size()){
            if(nums1[l]<=nums2[j]){
                dono.push_back(nums1[l++]);
            }
            else dono.push_back(nums2[j++]);
        }
        while(l<nums1.size()){
            dono.push_back(nums1[l++]);
        }
        while(j<nums2.size()){
            dono.push_back(nums2[j++]);
        }
        int n = dono.size();
        if (n % 2 == 1)
            return dono[n / 2]; // odd
        else
            return (dono[n / 2] + dono[n / 2 - 1]) / 2.0; // even
    }
    
};