class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<=n-k;i++){
            vector<int>temp(nums.begin()+i,nums.begin()+i+k);
            unordered_map<int,int>f;
            for(int num:temp){
                f[num]++;
            }
            vector<pair<int,int>>it(f.begin(),f.end());
            //to bacially map ko ek vector me store krlenge with the value and its count
            sort(it.begin(),it.end(),[](auto &a,auto &b){
                if(a.second==b.second) return a.first>b.first;
                return a.second>b.second;
            });
            unordered_set<int>top;
            for(int j=0;j<it.size() && j<x;j++){
                top.insert(it[j].first);
            }
            int sum=0;
            for(int num:temp){
                if(top.count(num)) sum+=num;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};