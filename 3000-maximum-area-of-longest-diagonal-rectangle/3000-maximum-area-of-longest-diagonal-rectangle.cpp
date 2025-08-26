class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int n=dim.size();
        double maxid=0;
        int maxia=0; //max rectangle area
        for(int i=0;i<n;i++){
            double dia=sqrt(dim[i][0]*dim[i][0]+dim[i][1]*dim[i][1]);
            if(dia>maxid){
                maxia=dim[i][0]*dim[i][1];
                maxid=dia;
            }
            if(dia==maxid)
                maxia=max(maxia,dim[i][0]*dim[i][1]);
        }
        return maxia;
    }
};