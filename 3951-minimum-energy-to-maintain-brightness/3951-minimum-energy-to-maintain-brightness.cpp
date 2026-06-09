class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long temp=(brightness+2)/3;
        sort(intervals.begin(),intervals.end());
        long long at=0; //active time;
        int l=intervals[0][0];
        int r=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int nl=intervals[i][0];
            int nr=intervals[i][1];
            if(nl<=r+1){
                r=max(r,nr);
            }
            else{
                at+=1LL*(r-l+1);
                l=nl;
                r=nr;
            }
        }
        at+=1LL*(r-l+1);
        return temp*at;

    }
};