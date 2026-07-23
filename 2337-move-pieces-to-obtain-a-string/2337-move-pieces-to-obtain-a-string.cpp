class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        int n=start.length();
        while(i<n||j<n){
            while(i<n && start[i]=='_') i++;
            while(j<n && target[j]=='_') j++;
            if(i==n || j==n) return i==n && j==n;
            if(start[i]!=target[j]) return 0;
            if(start[i]=='L' && i<j) return 0;
            if(start[i]=='R' && i>j) return 0;
            i++;
            j++;
        }
        return 1;
    }
};