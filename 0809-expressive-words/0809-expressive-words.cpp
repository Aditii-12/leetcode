class Solution {
public:
    bool func(string& s,string&w){
        int i=0;
        int j=0;
        int n=s.length();
        int m=w.length();
        while(i<n && j<m){
            if(s[i]!=w[j]) return 0;
            int l1=1;
            int l2=1;
            while(i+l1<n && s[i+l1]==s[i]) l1++;
            while(j+l2<m && w[j+l2]==w[j]) l2++;
            if(l1<l2) return 0;
            if(l1!=l2 && l1<3) return 0;
            i+=l1;
            j+=l2;
        }
        return i==n && j==m;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(func(s,words[i])) ans++;
        }
        return ans;
    }
};