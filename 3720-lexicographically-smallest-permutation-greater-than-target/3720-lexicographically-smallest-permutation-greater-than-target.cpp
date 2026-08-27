class Solution {
public:
    int n;
    vector<int>cnt;
    string f(int i,string &ans,bool isBig,string &target){
        if(i==n){
            if(isBig) return ans;
            return "";
        }
        for(int j=0;j<26;j++){
            if(cnt[j]==0) continue;
            char ch=j+'a';
            if(isBig || ch >=target[i]){
                ans.push_back(ch);
                cnt[j]--;
                bool newIsBig=isBig || (ch>target[i]);
                string res=f(i+1,ans,newIsBig,target);
                if(res!="") return res;
                ans.pop_back();
                cnt[j]++;
            }
        }
        return "";
    }
    string lexGreaterPermutation(string s, string target) {
        this->n=s.size();
        cnt.assign(26,0);
        for(auto it:s) cnt[it-'a']++;
        string ans="";
        return f(0,ans,false,target);
    }
};