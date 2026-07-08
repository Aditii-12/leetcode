class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int currmax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            currmax=max(currmax,nums[i][0]);
        }
        int s=0;
        int e=INT_MAX;
        while(true){
            auto [mini,pos]=pq.top();
            pq.pop();
            int list=pos.first;
            int ind=pos.second;
            if(currmax-mini<e-s){
                e=currmax;
                s=mini;
            }
            if(ind+1==nums[list].size()) break;
            int nextval=nums[list][ind+1];
            pq.push({nextval,{list,ind+1}});
            currmax=max(currmax,nextval);
        }
        return {s,e};
    }
};