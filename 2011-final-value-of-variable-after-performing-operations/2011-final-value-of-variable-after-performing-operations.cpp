class Solution {
public:
    bool func(string s){
    if(s=="++X"||s=="X++") return 1;
    return 0;
    }
    int finalValueAfterOperations(vector<string>& op) {
        int n=op.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(func(op[i])==1) ans++;
            else ans--;
        }
        return ans;
    }
    
};