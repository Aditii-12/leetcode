class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        for(int i=0;i<min(n,k);i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }
        vector<vector<int>>ans;
        while(k-- && !pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int i=curr[1];
            int j=curr[2];
            ans.push_back({nums1[i],nums2[j]});
            if(j+1<nums2.size()){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }
        }
        return ans;


    }
};