class Solution {
public:
    int findClosest(int x, int y, int z) {
        int k=abs(x-z);
        int l=abs(y-z);
        if(k>l){
            return 2;
        }
        if(k<l){
            return 1;
        }
        return 0;
    }
};