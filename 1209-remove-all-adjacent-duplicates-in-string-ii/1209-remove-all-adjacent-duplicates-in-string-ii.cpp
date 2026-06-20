class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>st;
        for(char ch:s){
            if(!st.empty() && st.back().first==ch){
                st.back().second++;
                if(st.back().second==k) 
                    st.pop_back();
            }
            else{
                st.push_back({ch,1});
            }
        }
        string ans;
        for(auto[c,f]:st){
            ans.append(f,c);
        }
        return ans;
    }
};