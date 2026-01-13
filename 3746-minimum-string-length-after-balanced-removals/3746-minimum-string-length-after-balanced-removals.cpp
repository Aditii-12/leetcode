class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0;
        int b=0;
        for(char ch:s){
            if(ch=='a') a++;
            else b++;
        }
        return abs(a-b);

    }
};