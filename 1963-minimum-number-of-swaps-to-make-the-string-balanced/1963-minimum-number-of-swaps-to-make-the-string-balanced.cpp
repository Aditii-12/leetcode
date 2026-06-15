class Solution {
public:
    int minSwaps(string s) {
        int bal=0;
        int maxi=0;
        for(auto p:s){
            if(p=='[') bal--;
            else bal++;
            maxi=max(maxi,bal);
        }
        return (maxi+1)/2;
    }
};