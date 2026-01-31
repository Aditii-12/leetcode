class Solution {
public:
//somewhat similar question as contigous array 525
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        int ans=0;
        int cnt=0;
        map<int,int>mpp;
        mpp[0]=-1;
        for(int i=0;i<n;i++){
            if(hours[i]<=8) cnt--;
            else cnt++;
            if(cnt>0) ans=i+1; //abi tk ka longest yhi hoga thats why we r not using max
            else{
                if(mpp.find(cnt-1)!=mpp.end())
                    ans=max(ans,i-mpp[cnt-1]);
                else mpp[cnt-1]=i; //store first occurence only
            }

        }
        return ans;
    }
};