class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int c=arr[(n-1)/2];
        int i=0;
        int j=n-1;
        vector<int>ans;
        while(i<=j && k--){
            int l=abs(c-arr[i]);
            int r=abs(c-arr[j]);
            if(l>r) {
                ans.push_back(arr[i]);
                i++;
            }
            else{
                ans.push_back(arr[j]);
                j--;
            }
        }
        return ans;
    }
};