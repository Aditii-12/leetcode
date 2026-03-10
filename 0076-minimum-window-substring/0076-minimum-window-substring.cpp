class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        if(n1==0||n2==0) return "";
        unordered_map<char,int>mppt;
        for(auto it:t){
            mppt[it]++;
        }
        unordered_map<char,int>mpp; //freq in a window
        int l=0;
        int r=0;
        int start=0; //to see the start index and we also see min lengtjh
        //in the end to return the mini substring
        int mini=INT_MAX;
        int req=mppt.size(); //no of unique character needed
        int fo=0; //tracks how many char satisfy their freq
        while(r<n1){
            mpp[s[r]]++;
            if(mppt.count(s[r]) && mppt[s[r]]==mpp[s[r]]) fo++;
            while(l<=r && fo==req){
                if(r-l+1<mini){
                    mini=r-l+1;
                    start=l;   
                }
                mpp[s[l]]--; //shrinking window
                if (mppt.count(s[l]) && mpp[s[l]] <mppt[s[l]]) {
                    fo--;
                }
                l++;
            }
            r++;
        }
        return mini==INT_MAX ? "" : s.substr(start,mini);
    }
};