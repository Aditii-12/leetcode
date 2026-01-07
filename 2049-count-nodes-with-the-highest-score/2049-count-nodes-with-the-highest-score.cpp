using ll=long long;
class Solution {
public:
    ll maxi=0; //max score
    int cnt=0;
    int n;
    vector<vector<int>>tree;
    ll dfs(int u){
        ll score=1; //isme we will multiply
        ll sz=0; //child size(left and right alg se)

        for(int v:tree[u]){ //seeing child of that node
            ll childsz=dfs(v); //fir particulr child me dfs krenge
            score*=childsz; //score me left child ka and then right child ka sum mutiply krenge
            sz+=childsz; //to find that subtree[n] ;
            //which can be letter used to calculate the size of parent side
            //after removing n-subtree[n] which is size
        }
        ll rest=n-sz-1; //-1 because removing that node too
        if(rest>0){
            score*=rest;
        }
        if(score>maxi) {maxi=score; 
            cnt=1;
        }
        else if(score==maxi) cnt++;
        return sz+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size(); //no of nodesin tree
        tree.assign(n,{});
        for(int i=1;i<n;i++){
            tree[parents[i]].push_back(i);
        }
        dfs(0);
        return cnt;
    }
};