class Solution {
public:
    bool valid(int i,string &s){
        int n=s.length();
        if(s[i]>='a' && s[i]<='z') return 1;
        if(s[i]=='-' && i>0 && i<n-1 && ('a'<=s[i-1] && s[i-1]<='z') &&
                ('a'<=s[i+1] && s[i+1]<='z')) return 1;
        return 0;
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto it:chunks){
            s+=it;
        }
        unordered_map<string,int>freq;
        int n=s.size();
        string curr;
        for(int i=0;i<n;i++){
            if(valid(i,s)) curr+=s[i];
            else{
                if(!curr.empty()){
                    freq[curr]++;
                    curr="";
                }
            }
        }
        if(!curr.empty()) freq[curr]++;
        int m=queries.size();
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            ans[i]=freq[queries[i]];
        }
        return ans;
    }
};