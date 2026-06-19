class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum=0;
        int maxsum=0;
        for(auto it:gain){
            sum+=it;
            maxsum=max(sum,maxsum);
        }
        return maxsum;
    }
};