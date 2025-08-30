class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int no=k;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k){
                k++;
            }
            if(arr[i]>k)
            break;
        }
        return k;
    }
};