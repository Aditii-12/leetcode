class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1==nums2) return 0;
        map<int,int>cnt1,cnt2,cnt12;
        for(int num:nums1){
            cnt1[num]++;
            cnt12[num]++;
        }
        for(int num:nums2){
            cnt2[num]++;
            cnt12[num]++;
        }
        for(auto it:cnt12){
            if(it.second%2==1) return -1;
        }
        int ans=0;
        for(auto it:cnt12){
            int v1=cnt1[it.first];
            int v2=cnt2[it.first];
            ans+=abs(v1-v2)/2;
        }
        return ans/2;
    }
};