class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums2.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int j=0;j<min(n,k);j++){
            pq.push({nums1[0]+nums2[j],0,j});
        }
        vector<vector<int>>ans;
        while(k-- && !pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int i=curr[1];
            int j=curr[2];
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<nums1.size()){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
            }
        }
        return ans;
    }
};