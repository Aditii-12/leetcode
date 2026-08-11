class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n, 1);
        for(int i=1;i<m;i++){
            vector<int> c(n, 1);
            for(int j=1;j<n;j++){
                c[j]=c[j-1]+v[j];
            }
            v=c;
        }
        return v[n - 1];        
    }
};