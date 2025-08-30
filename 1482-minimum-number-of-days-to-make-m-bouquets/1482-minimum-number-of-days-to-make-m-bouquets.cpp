class Solution {
public:
    bool possible(vector<int>& bloomday, int mid , int m , int k){
        int n = bloomday.size();
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < n; i++) {
            if (bloomday[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;  // reset because flowers need to be adjacent
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        if (1LL*m * k > bloomday.size())
            return -1;
        // my answer will lie between min element and maxel of array
        int mini = *min_element(bloomday.begin(), bloomday.end());
        int maxi = *max_element(bloomday.begin(), bloomday.end());
        int low = mini;
        int high = maxi;
        int ans=-1;
        while (low <= high) {
            int mid=(low+high)/2;
            if(possible(bloomday,mid,m,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};