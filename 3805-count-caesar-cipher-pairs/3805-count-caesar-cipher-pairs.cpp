class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        int m=words[0].size();
        long long ans=0;
        unordered_map<string,long long>mpp;
        for(string s:words){
            int sh=s[0]-'a'; //first letter ko a tk le jane k liye kitne shifts
            string key=s; //copy of that word
            for(char &ch:key){
                ch=(ch-'a'-sh+26) % 26+'a';

                // cbc-- to first letter ko a krdiya which means shift of 2
                //now hr charcater ko 2 peeche shift krenge
                //to for b
                //ch=ch-'a' //b-a=1 //1-shift== 1-2=-1 then +26 == 25+'a'=y
                //to b ko 2 peeche shift krne pr we get z
            }
            mpp[key]++;
        }
        for(auto it:mpp){
            long long k=it.second;
            ans+=k*(k-1)/2;
        }
        return ans;
    }

};