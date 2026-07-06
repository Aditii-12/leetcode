class Solution {
public:
    bool func(int mid,string &s,string &p,vector<int>& removable){
        vector<bool>removed(s.size(),0);
        for(int i=0;i<mid;i++){
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
        int k=removable.size();
        int l=0;
        int h=k;
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(mid,s,p,removable)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};