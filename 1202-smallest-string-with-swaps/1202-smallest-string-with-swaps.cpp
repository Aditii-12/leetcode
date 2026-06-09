class Solution {
public:
    vector<int>par;
    vector<int>rank;
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unionn(int x,int y){
        int u=find(x);
        int v=find(y);
        if(u==v) return;
        if(rank[u]>rank[v]) par[v]=u;
        else if(rank[v]>rank[u]) par[u]=v;
        else {
            par[u]=v;
            rank[u]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n =s.length();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto it:pairs){
            unionn(it[0],it[1]);
        }
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[find(i)].push_back(i);
        }
        string ans=s;
        for(auto [root,ind]:mpp){
            string chars="";
            for(auto it:ind){
                chars+=s[it];
            }
            sort(ind.begin(),ind.end());
            sort(chars.begin(),chars.end());
            for(int i=0;i<ind.size();i++){
                ans[ind[i]]=chars[i];
            }
        }
        return ans;
    }
};