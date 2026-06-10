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
        if(rank[u]>rank[v]) par[u]=v;
        else if(rank[u]<rank[v]) par[u]=v;
        else {
            rank[u]++;
            par[u]=v;
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& swap) {
        int n=source.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto it:swap){
            int u=find(it[0]);
            int v=find(it[1]);
        }
        for(auto it:swap){
            unionn(it[0],it[1]);
        }
        unordered_map<int,vector<int>>comp;
        for(int i=0;i<n;i++){
            comp[find(i)].push_back(i);
        }
        int ans=0;
        for(auto &[root,idxs]:comp){
            unordered_map<int,int>freq;
            for(int idx:idxs){
                freq[source[idx]]++;
            }
            for(int idx:idxs){
                if(freq[target[idx]]>0) freq[target[idx]]--;
                else ans++;
            }
        }
        return ans;
    }
};