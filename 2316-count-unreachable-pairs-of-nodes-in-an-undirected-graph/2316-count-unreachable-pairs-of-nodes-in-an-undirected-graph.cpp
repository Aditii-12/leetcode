class Solution {
public:
vector<int>par;
vector<int>rank;
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unionn(int x,int y){
    int x_par=find(x);
    int y_par=find(y);
    if(x_par==y_par) return;
    if(rank[x_par]>rank[y_par]) par[y_par]=x_par;
    else if(rank[x_par]<rank[y_par]) par[x_par]=y_par;
    else {
        rank[x_par]++;
        par[y_par]=x_par;
    }    
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        par.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        map<int,int>mpp; 
        //GOOD TRICK TO COUNT NODES IN EACH COMPONENT
        for(auto it:edges){
            unionn(it[0],it[1]);
        }
        for(int i=0;i<n;i++){
            //basically we will find parent for each node
            //and then mpp me uska count bdhayenge
            //lets say 5 4logo ka parent h plus vo b h
            //mpp[5]=5 hojayega which means 5 ke component me 5 nodes h
            int p=find(i);
            mpp[p]++;
        }
        long long ans=0;
        for(auto it:mpp){
            ans+=(long long)it.second*(n-it.second);
            //to basically ek component ke log baki sbse multiply krenge
        }
        return ans/2;



    }
};