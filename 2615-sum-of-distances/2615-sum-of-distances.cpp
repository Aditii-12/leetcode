class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        vector<long long>ans(n,0);
        for(auto &it:mpp){
            vector<int>& pos=it.second;
            int k=pos.size();
            vector<long long>pre(k,0);
            pre[0]=pos[0];
            for(int i=1;i<k;i++){
                pre[i]=pre[i-1]+pos[i];
            }
            for(int i=0;i<k;i++){
                long long l=0,r=0;
                if(i>0){
                    l=(long long)pos[i]*i-pre[i-1];
                }
                if(i<k-1){
                    r=pre[k-1]-pre[i]-(long long) pos[i] *(k-i-1);
                }
                ans[pos[i]]=l+r;
            }
        }
        return ans;
    }
};