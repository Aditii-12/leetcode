class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int n=arr.size();
        if(n<k) return 0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int cnt=0;
        if(sum/k>=th) cnt++;
        int l=0;
        int r=k;
        while(r<n){
            sum-=arr[l];
            sum+=arr[r];
            if(sum/k>=th) cnt++;
            r++;
            l++;
        }
        return cnt;

    }
};