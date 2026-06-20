class Solution {
public:
    string removeDuplicates(string s, int k) {
        string res;
        for(char ch:s){
            res.push_back(ch);
            if(res.size()>=k){
                string temp(k,ch);
                if(res.substr(res.size()-k)==temp){
                    res.erase(res.size()-k);
                }
            }
        }
        return res;
    }
};