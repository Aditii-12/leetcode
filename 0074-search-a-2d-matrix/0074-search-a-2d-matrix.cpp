class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0;
        int h=m*n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int ro=mid/m;
            int col=mid%m;
            if(matrix[ro][col]==target) return 1;
            if(matrix[ro][col]<target) l=mid+1;
            else h=mid-1;
        }
        return 0;

    }
};