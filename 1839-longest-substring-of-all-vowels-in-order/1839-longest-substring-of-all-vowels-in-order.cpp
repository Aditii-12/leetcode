class Solution {
public:
//only consitst of aeiou . so we can store in set and see size of set
//and another condiiton is usse chota hona chahiye usse pehle wala
    int longestBeautifulSubstring(string s) {
        int n=s.size();
        if(n<5) return 0;
        set<char>st;
        int l=0; //starting of a valid substring
        int r=0;
        int maxi=0;
        while(r<n){
            if(r>l && s[r]<s[r-1]){ //should not be decreasing
                l=r; //restart our window
                st.clear();
            }
            st.insert(s[r]);
            if(st.size()==5){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi;
    }
};