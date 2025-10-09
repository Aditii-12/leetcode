class Solution {
public:
    string reverseWords(string s) {
         stringstream s2(s);
         vector<string> ans;
         string result;
         string word;
         while(s2>>word){
            ans.push_back(word);
         }
         reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size()-1;i++){
            result+=ans[i];
            result+=" ";
         }
         result+=ans[ans.size()-1];
         return result;

    }
};