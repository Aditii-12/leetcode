class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        bool f=1,p=1;
        for(int i=0;i<s1.length();i++){
            if(s1[i]<s2[i]) f=0;
            if(s2[i]<s1[i]) p=0;
        }
        return f||p;

    }
};