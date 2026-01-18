class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0);
        int m=bookings.size();
        for(auto &it:bookings){
            diff[it[0]-1]+=it[2]; //kyuki question me 1 based indexing h
            if(it[1]<n) diff[it[1]]-=it[2]; //it[1]+1-1==it[1];
        }
        for(int i=1;i<n;i++){
            diff[i]+=diff[i-1];
        }
        return diff;

    }
};