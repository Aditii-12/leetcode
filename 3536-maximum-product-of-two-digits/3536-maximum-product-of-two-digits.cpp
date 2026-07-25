class Solution {
public:
    int maxProduct(int n) {
        int k=n,x=0;
        vector<int>pos;
        while(k>0){
            x++;
            int y=k%10;
            k=k/10;
            pos.push_back(y);
        }
        sort(pos.begin(),pos.end());
        return pos[x-1]*pos[x-2];
    }
};