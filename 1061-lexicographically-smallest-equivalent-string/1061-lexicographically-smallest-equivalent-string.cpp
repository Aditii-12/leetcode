class Solution {
public:
vector<int>par;
    int find(int x){
        if(par[x]==x) return x;
        else return par[x]=find(par[x]);
    }
    void unionn(int x,int y){
        int parx=find(x);
        int pary=find(y);
        if(parx==pary) return;
        else if(parx<pary) par[pary]=parx;
        else par[parx]=pary;
    }
    string smallestEquivalentString(string s1, string s2, string basestr) {
        int n=s1.length();
        par.resize(26);
        for(char i=0;i<26;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            unionn(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(int i=0;i<basestr.size();i++){
            ans+=(find(basestr[i]-'a')+'a');
        }
        return ans;
    }
};