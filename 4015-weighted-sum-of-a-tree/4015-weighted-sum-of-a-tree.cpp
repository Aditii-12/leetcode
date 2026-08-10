class Solution {
public:
    long long weightedSum(vector<int>& par, vector<int>& nums) {
        int n=par.size();
        vector<vector<int>>child(n);
        for(int i=1;i<n;i++){
            child[par[i]].push_back(i);
        }
        vector<int>depth(n);
        queue<int>q;
        depth[0]=1;
        q.push(0);
        int h=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto it:child[u]){
                depth[it]=depth[u]+1;
                h=max(h,depth[it]);
                q.push(it);
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=1LL*nums[i]*(h-depth[i]+1);
        }
        return ans;
    }
};