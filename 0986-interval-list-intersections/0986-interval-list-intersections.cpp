class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<first.size() && j<second.size()){
            int l=max(first[i][0],second[j][0]);
            int r=min(first[i][1],second[j][1]);
            if(l<=r) ans.push_back({l,r});
            if(first[i][1]<second[j][1]) i++;
            else j++;
        }
        return ans;
    }
};