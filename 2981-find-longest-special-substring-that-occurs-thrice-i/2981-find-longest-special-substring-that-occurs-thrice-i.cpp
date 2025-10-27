class Solution {
public:
    int maximumLength(string s) {
        int n=s.length();
        map<string,int>mpp;
        for(int i=0;i<n;i++){
            string temp="";
            char ch=s[i];
            for(int j=i;j<n;j++){
                if(s[j]==ch){
                    temp+=ch;
                    mpp[temp]++;
                }
                else break;
            }
        }
        int maxlen=-1;
        for(auto it:mpp){
            if(it.second>=3){
                maxlen=max(maxlen,(int)it.first.length());
            }
        }
        return maxlen;
    }
};