class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& oi, int fs, int fe) {
        sort(oi.begin(),oi.end());
        vector<vector<int>>temp;
        for(auto it:oi){
            if(temp.empty()||temp.back()[1]+1<it[0]){
                temp.push_back(it);
            }
            else{
                temp.back()[1]=max(temp.back()[1],it[1]);
            }
        }
        vector<vector<int>>res;
        for(auto it:temp){
            int a=it[0];
            int b=it[1];
            if(b<fs || a>fe){
                res.push_back({a,b});
            }
            else{
                if(a<fs){
                    res.push_back({a,fs-1});
                }
                if(b>fe){
                    res.push_back({fe+1,b});
                }
            }
        }
        return res;
    }
};