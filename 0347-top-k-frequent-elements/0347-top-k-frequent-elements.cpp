class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for (int x:nums) mpp[x]++;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        for (auto &it:mpp) {
            pq.push({it.second,it.first}); //freq,number
            if(pq.size()>k) pq.pop(); //to pq sif top k elements hi store kregi 
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
