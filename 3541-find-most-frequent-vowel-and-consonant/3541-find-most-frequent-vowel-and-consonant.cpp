class Solution {
public:
bool isvowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
    return false;
}
    int maxFreqSum(string s) {
        map<char,int>vowel;
        map<char,int>novowel;
        for(auto it:s){
            if(isvowel(it)) vowel[it]++;
            else novowel[it]++;
        }
        int maxv=0;
        int maxnov=0;
        for(auto it:vowel){
            maxv=max(maxv,it.second);
        }
        for(auto it:novowel){
            maxnov=max(maxnov,it.second);
        }
        return maxv+maxnov;
    }
};