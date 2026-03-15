class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({nums2[i],nums1[i]});
        }
        sort(p.rbegin(),p.rend());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        long long ans=0;
        for(int i=0;i<k-1;i++){
            pq.push(p[i].second);
            sum+=p[i].second;
        }
        for(int i=k-1;i<n;i++){
            sum+=p[i].second;
            pq.push(p[i].second);
            ans=max(ans,sum*p[i].first);
            sum-=pq.top();
            pq.pop();
        }
        return ans;
    }
};