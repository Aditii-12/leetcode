class Solution {
public:
//finding window of size n-k with min sum
//so left card will give max sum
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int win=n-k;
        int s=accumulate(c.begin(),c.end(),0);
        if(win==0) return s;
        int sum=0;
        for(int i=0;i<win;i++){
            sum+=c[i];
        }
        int mini=sum;
        int r=win;
        int l=0;
        while(r<n){
            sum+=c[r];
            sum-=c[l];
            r++;
            l++;
            mini=min(mini,sum);
        }
        
        return s-mini;
    }
};