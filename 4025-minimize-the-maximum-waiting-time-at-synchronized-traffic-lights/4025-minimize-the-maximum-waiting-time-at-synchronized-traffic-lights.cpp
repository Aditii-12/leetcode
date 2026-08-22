class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi=INT_MIN;
        int ans=INT_MIN;

        for (int it:lights) {
            maxi=max(maxi,it);
        }
        for (int it:arrivalTime) {
            int curr=it%period;
            if (curr>=maxi) {
                ans= max(ans,period-curr);
            }
        }
        return ans==INT_MIN?0:ans;
    }
};