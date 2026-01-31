class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<=26;i++){ //hpw many unique characters we want in our window
        //to ye jitna b count hoga utne letters atleast k hone chahiye
            vector<int>freq(26,0);
            int l=0;
            int r=0;
            int unique=0; //no of unique characters 
            int cnt=0; //no of char appearinf atleast k time
            while(r<n){
                if(unique<=i){ //aaram sr window expand kr skte h
                    int idx=s[r]-'a';
                    if(freq[idx]==0) //new unique char added
                    {
                        unique++;
                    }
                    freq[idx]++;
                    if(freq[idx]==k) cnt++;

                    r++;
                }
                else{ //too many unique char. shrinkwindow
                    int idx=s[l]-'a';
                    if(freq[idx]==k) cnt--;
                    freq[idx]--;
                    if(freq[idx]==0) unique--;
                    l++;
                }
                if(unique==i && unique==cnt){
                    ans=max(ans,r-l);
                }
            }
            
        }
        return ans;
    }
};