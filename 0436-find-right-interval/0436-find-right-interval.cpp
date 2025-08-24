class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& interval) {
        int n=interval.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i]={interval[i][0],i};
        }
        sort(v.begin(),v.end());
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            int target=interval[i][1];
            int l=0;
            int h=n-1;
            while(l<=h){
                int m=(l+h)/2;
                if(v[m].first>=target) h=m-1;
                else l=m+1;
            }
            if(l<n) ans[i]=v[l].second;
        }
        return ans;
    }
};