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
    if(rank[x_par]>rank[y_par]) par[y_par]=x_par;
    else if(rank[x_par]<rank[y_par]) par[x_par]=y_par;
    else{
        rank[x_par]++;
        par[y_par]=x_par;
    }
}
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(!mpp.count(mail)) mpp[mail]=i;
                else{
                    unionn(i,mpp[mail]);
                }
            }
        }
        unordered_map<int,set<string>>m;
        for(int i=0;i<n;i++){
            int root=find(i);
            for(int j=1;j<accounts[i].size();j++){
                m[root].insert(accounts[i][j]);
            }
        }
        vector<vector<string>>ans;
        for(auto [root,emails]:m){
            vector<string>curr;
            curr.push_back(accounts[root][0]);
            for(auto mail:emails){
                curr.push_back(mail);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};