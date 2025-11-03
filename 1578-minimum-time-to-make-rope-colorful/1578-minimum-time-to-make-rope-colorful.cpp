class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n=colors.size();
        int timee=0;
        int i=0;
        int j=0;
        while(i<n&&j<n){
            int maxi=0;
            while(j<n && colors[i]==colors[j]){
                timee+=time[j];
                maxi=max(maxi,time[j]);
                j++;
            }
            timee-=maxi;
            i=j;

        }
        return timee;
    }
};