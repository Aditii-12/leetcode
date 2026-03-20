class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int>freq(1024,0); //2^10 possible masks
        freq[0]=1;
        int mask=0;
        long long ans=0;
        for(char ch:word){
            mask^=(1<<(ch-'a')); //vo char ka bit toggle krdenge
            ans+=freq[mask]; //pehle jitni br aa chuka h utna we will add
            //upr wala is for all even 
            for(int i=0;i<10;i++){ //this is for one odd case, mask will change by 1 bit
                ans+=freq[mask^(1<<i)];
            }
            freq[mask]++;
        }
        return ans;
    }
};