class Solution {
public:
    vector<int>parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        else
            return parent[x]=find(parent[x]);
    }
    void unionn(int x,int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p == y_p) return;
        if(rank[x_p]>rank[y_p]){
            parent[y_p]=x_p;
        }
        else if(rank[x_p]<rank[y_p]){
            parent[x_p]=y_p;
        }
        else {
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }

        for(auto s:equations){
            if(s[1]=='=') { //means two char are equal to unka union
            unionn(s[0]-'a',s[3]-'a');
            }
        }
        //find not equal wale case and validate
        for(auto s:equations){
            if(s[1]=='!'){
                int p1=find(s[0]-'a');
                int p2=find(s[3]-'a');
                if(p1==p2) return false;
            }
        }
        return true;
    }
};