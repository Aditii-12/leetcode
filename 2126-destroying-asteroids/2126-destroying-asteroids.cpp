class Solution {
public:
    using ll=long long;
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(),ast.end());
        ll ma=mass;
        int i=0;
        while(i<ast.size()){
            if(ma<ast[i]) return 0;
            ma+=ast[i];
            i++;
        }
        return 1;
    }
};