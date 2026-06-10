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
bool func(string &s1,string &s2){
    int n=s1.length();
    int diff=0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]) diff++;
        if(diff>2) return 0;
    }
    return (diff==0 || diff==2);
}
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(func(strs[i],strs[j])) unionn(i,j);
            }
        }
        int grp=0;
        for(int i=0;i<n;i++){
            if(find(i)==i) grp++;
        }
        return grp;
    }
};