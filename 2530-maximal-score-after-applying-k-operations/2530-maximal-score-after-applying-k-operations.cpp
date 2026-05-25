class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        long long ans=0;
        for(auto it:nums) pq.push(it);
        while(k--){
            auto it=pq.top();
            pq.pop();
            ans+=it;
            pq.push(ceil(it/3.0));
        }
        return ans;
    }
};