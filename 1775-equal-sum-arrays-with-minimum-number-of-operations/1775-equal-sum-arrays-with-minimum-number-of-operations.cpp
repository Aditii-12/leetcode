class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(6*n<m || 6*m<n) return -1;
        int sum1=accumulate(nums1.begin(),nums1.end(),0);
        int sum2=accumulate(nums2.begin(),nums2.end(),0);
        if(sum1>sum2){
            swap(sum1,sum2);
            swap(nums1,nums2);
        }
        vector<int>g;
        for(int i:nums1){
            g.push_back(6-i);
        }
        for(int i:nums2){
            g.push_back(i-1);
        }
        int diff=sum2-sum1;
        sort(g.rbegin(),g.rend());
        int op=0;
        int i=0;
        while(diff>0){
            diff-=g[i];
            i++;
            op++;
        }
        return op;

    }
};