class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(citations[m]>=n-m) //means n-m is valid h index
            //to ab left me move krege jisse n-m bdega h index bgera
            //n-m is h index to agr 
                h=m-1;
            else l=m+1;
        }
        return n-l;
    }
};