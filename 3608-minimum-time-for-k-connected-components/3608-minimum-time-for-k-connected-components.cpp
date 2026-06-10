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
    if(rank[u]>rank[v]){
        par[v]=u;
    } 
    else if(rank[u]<rank[v]){
        par[u]=v;
    }
    else{
        par[u]=v;
        rank[u]++;
    }
}
    int minTime(int n, vector<vector<int>>& edges, int k) {
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        rank.resize(n,0);
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){
            return a[2]>b[2];
        });
        int comp=n;
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            int t=e[2];
            int pu=find(u);
            int pv=find(v);
            if(pu!=pv){
                unionn(u,v);
                comp--;
            }
            if(comp<k) return t;
        }
        return 0;

    }
};