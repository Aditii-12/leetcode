class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& pro, vector<int>& worker) {
        vector<pair<int,int>>p;
        int n=diff.size();
        for(int i=0;i<n;i++){
            p.push_back({diff[i],pro[i]});
        }
        sort(worker.begin(),worker.end());
        sort(p.begin(),p.end());
        int ans=0;
        int maxi=0;
        int j=0;   //pointer for difficulty vector
        for(int i=0;i<worker.size();i++){
            while(j<n && p[j].first<=worker[i]) {
                maxi=max(maxi,p[j].second);
                j++;
            }
            ans+=maxi;
        }
        return ans;
    }
};