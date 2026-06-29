class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.length();
        int swapi=-1;
        int swapj=-1;
        int maxr=s[n-1];
        int maxidx=n-1;
        for(int i=n-2;i>=0;i--){
            if(s[i]>maxr){
                maxr=s[i];
                maxidx=i;
            }
            else if(s[i]<maxr){
                swapi=i;
                swapj=maxidx;
            }
        }
        if(swapi!=-1) swap(s[swapi],s[swapj]);
        return stoi(s);
    }
};