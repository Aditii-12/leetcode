class Solution {
public:
    long long maximumHappinessSum(vector<int>& hap, int k) {
        sort(hap.rbegin(),hap.rend());
        if(k==1) return hap[0];
        long long sum=0;
        sum+=hap[0];
        int i=1;
        k--;
        for(int j=1;j<=k;j++){
            sum+=max(0,hap[i]-j);
            i++;
        }
        return sum;
    }
};