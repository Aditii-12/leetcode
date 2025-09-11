class Solution {
public:
    bool isvow(char c){
        return c=='a'||c=='e'||c=='o'||c=='u'||c=='i' 
            ||c=='A'||c=='E'||c=='O'||c=='U'||c=='I';
        }
    string sortVowels(string s) {
        string temp;
        for(char c:s){
            if(isvow(c)) temp+=c;
        }
        sort(temp.begin(),temp.end());
        string ans;
        int i=0;
        for(int j=0;j<s.size();j++){
            if(isvow(s[j])) ans+=temp[i++];
            else ans+=s[j];
        }
        return ans;
    }
};