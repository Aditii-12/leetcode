class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string>st;
        for(auto it:words){
            string e,o;
            for(int i=0;i<it.size();i++){
                if(i%2==0) e+=it[i];
                else o+=it[i];
            }
            sort(e.begin(),e.end());
            sort(o.begin(),o.end());
            st.insert(e+"#"+o);
        }
        return st.size();
    }
};