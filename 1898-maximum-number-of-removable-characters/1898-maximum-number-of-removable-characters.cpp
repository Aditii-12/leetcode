class Solution {
public:
    bool func(string s,string p,vector<int>& removable,int k){
        vector<bool>removed(s.size(),0);
        for(int i=0;i<k;i++){
            removed[removable[i]]=1;
        }
        int j=0; //for string p pointer
        for(int i=0;i<s.size();i++){ //for string s pointer
            if(removed[i]) continue;
            if(j<p.size()&&s[i]==p[j]) j++;
        }
        return j==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0;
        int r=removable.size();
        int ans=l;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(func(s,p,removable,mid)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
}
};