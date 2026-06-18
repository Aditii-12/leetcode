class Solution {
public:
    int minProcessingTime(vector<int>& pt, vector<int>& t) {
        sort(t.rbegin(),t.rend());
        sort(pt.begin(),pt.end());
        int i=0;
        int k=0;
        int ans=0;
        while(i<t.size()){
            ans=max(pt[k]+t[i],ans);
            i+=4;
            k++;
        }
        return ans;
    }
};