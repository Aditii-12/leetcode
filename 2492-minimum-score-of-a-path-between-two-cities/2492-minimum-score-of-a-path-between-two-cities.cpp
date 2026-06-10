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
    if(u==v) return ;
    if(rank[u]>rank[v]) par[v]=u;
    else if(rank[v]>rank[u]) par[u]=v;
    else{
        par[u]=v;
        rank[v]++;
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        for(auto it:roads){
            unionn(it[0],it[1]);
        }
        int root=find(1);
        int ans=INT_MAX;
        for(auto it:roads){
            if(find(it[0])==root) ans=min(ans,it[2]);
        }
        return ans;
    }
};