class Solution {
public:
vector<int>para,parb;
vector<int>ranka,rankb;
int finda(int x){
    if(para[x]==x) return x;
    return para[x]=finda(para[x]);
}
int findb(int x){
    if(parb[x]==x) return x;
    return parb[x]=findb(parb[x]);
}
    bool unionna(int x,int y){
        int u=finda(x);
        int v=finda(y);
        if(u==v) return 0;
        if(ranka[u]>ranka[v]) para[u]=v;
        else if(ranka[u]<ranka[v]) para[u]=v;
        else {
            ranka[u]++;
            para[u]=v;
        }
        return 1;
    }
    bool unionnb(int x,int y){
        int u=findb(x);
        int v=findb(y);
        if(u==v) return 0;
        if(rankb[u]>rankb[v]) parb[u]=v;
        else if(rankb[u]<rankb[v]) parb[u]=v;
        else {
            rankb[u]++;
            parb[u]=v;
        }
        return 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        para.resize(n+1);
        ranka.resize(n+1,0);
        parb.resize(n+1);
        rankb.resize(n+1,0);
        for(int i=1;i<=n;i++){
            para[i]=i;
            parb[i]=i;
        }
        int rem=0;
        int useda=0;
        int usedb=0;
        for(auto &e:edges){
            if(e[0]!=3) continue;
            bool a=unionna(e[1],e[2]);
            bool b=unionnb(e[1],e[2]);
            if(a){
                useda++;
                usedb++;
            }
            else{
                rem++;
            }
        }
        for(auto &e:edges){
            if(e[0]!=1) continue;
            if(unionna(e[1],e[2]))
                useda++;
            else
                rem++;
        }
        for(auto &e:edges){
            if(e[0]!=2) continue;
            if(unionnb(e[1],e[2]))
                usedb++;
            else
                rem++;
        }
        if(useda!=n-1 || usedb!=n-1)
            return -1;
        return rem;
    }
};