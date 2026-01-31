class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res=letters[0];
        bool f=0;
        for(char ch:letters){
            if(!f){
                if(ch>target){
                    res=ch;
                    f=!f;
                }
            }
            else{
                if(ch>target && ch<res) res=ch;
            }
        }
        return res;
    }
};