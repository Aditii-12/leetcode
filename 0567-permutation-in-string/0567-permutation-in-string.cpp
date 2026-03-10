class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int> mpps1(26,0);
        vector<int> mpps2(26,0);
        if(m<n) return 0;
        for(int i=0;i<n;i++){
            mpps1[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            mpps2[s2[i]-'a']++; //first window
        }
        if(mpps1==mpps2) return 1;
        int l=0,r=n;
        while(r<m){
            mpps2[s2[r]-'a']++;
            mpps2[s2[l]-'a']--;
            l++;
            r++;
            if(mpps1==mpps2) return 1;
        }
        return 0;

    }
};