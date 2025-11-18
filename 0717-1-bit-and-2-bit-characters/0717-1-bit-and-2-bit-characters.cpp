class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        bool f=0;
        int i=0;
        for(;i<n-1;i++){
            if(bits[i]==1) i++;
        }
        return i==n-1;
    }
};