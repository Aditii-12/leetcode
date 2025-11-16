class Solution {
public:
    const int P=int(1E9)+7;
    int numSub(string s) {
        long long ans=0;
        long long temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                ans+=temp*(temp+1)/2;
                temp=0;
            }
            else temp++;
        }
        ans+=temp*(temp+1)/2;
        return ans%P;

    }
};