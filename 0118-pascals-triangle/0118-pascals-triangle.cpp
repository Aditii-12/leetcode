class Solution {
public:
    int nCr(int row,int col){
        long long res=1;
        for(int i=0;i<col;i++){
            res=res*(row-i);
            res=res/(i+1);
        }
        return int(res);
    }
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        for(int r=1;r<=n;r++){
            vector<int> level;
            for(int c=1;c<=r;c++){
                level.push_back(nCr(r-1,c-1));
            }
            ans.push_back(level);

        }
        return ans;
    }
};