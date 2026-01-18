class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>diff(1001,0);
        for(auto &it:trips){
            diff[it[1]]+=it[0];
            diff[it[2]]-=it[0];
        }
        if(diff[0]>capacity) return 0;
        for(int i=1;i<1000;i++){
            diff[i]+=diff[i-1];
            if(diff[i]>capacity) return 0;
        }
        return 1;

    }
};