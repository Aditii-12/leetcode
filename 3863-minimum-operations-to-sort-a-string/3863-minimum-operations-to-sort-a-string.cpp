class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        string t=s;
        sort(t.begin(),t.end());
        if(t==s) return 0;
        if(s.size()==2) return -1;
        char mini=*min_element(s.begin(),s.end());
        char maxi=*max_element(s.begin(),s.end());
        if(s[0]==mini || s[n-1]==maxi) return 1;
        if(s[0]==maxi && s[n-1]==mini){
            for(int i=1;i<n-1;i++){
                if(s[i]==mini || s[i]==maxi) return 2;
            }
            return 3;
        }
        else return 2;
    }
};