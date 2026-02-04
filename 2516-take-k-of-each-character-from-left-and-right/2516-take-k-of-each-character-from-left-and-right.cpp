class Solution {
public:
//outisde window we need atleast k of each char
//so inside window we need to have atmost total-k
//and inside window ki max value lelnge
    int takeCharacters(string s, int k) {
        int n=s.length();
        int cnta=0;
        int cntb=0;
        int cntc=0;
        for(char ch:s){
            if(ch=='a') cnta++;
            else if(ch=='b') cntb++;
            else cntc++;
        }
        if(cnta<k||cntb<k||cntc<k) return -1;
        int wa=0; //a inside window
        int wb=0;
        int wc=0;
        int l=0,r=0;
        int maxi=0;
        while(r<n){
            if(s[r]=='a') wa++;
            else if(s[r]=='b') wb++;
            else wc++;
            while(cnta-wa<k||cntb-wb<k||cntc-wc<k){ //window ke bhr kam hogye to shrink
                if(s[l]=='a') wa--;
                else if(s[l]=='b') wb--;
                else wc--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return n-maxi;
    }
};