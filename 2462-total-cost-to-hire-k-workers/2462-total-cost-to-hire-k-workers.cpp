class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int l=0;
        int r=n-1;
        for(int i=0;i<candidates && l<=r;i++){ //filling from left
            pq.push({costs[l],l});
            l++;
        }
        for(int i=0;i<candidates && l<=r;i++){
            pq.push({costs[r],r});
            r--;
        }
        long long ans=0;
        while(k--){
            auto curr=pq.top();
            pq.pop();
            int cost=curr.first;
            int ind=curr.second;
            ans+=cost;
            if(l<=r){
                if(ind<l){
                    pq.push({costs[l],l});
                    l++;
                }
                else{
                    pq.push({costs[r],r});
                    r--;
                }
            }
        }
        return ans;
    }
};