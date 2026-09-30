class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n=s.length();
        vector<int>ans(n);
        //point is max (a,b) will be (max depth of original seq/2)
        //to a ko 1 denge then b ko ek
        //basically dono ko equal baatne ka try krenge
        //and odd ke case me ek bch jayega to vo kisi ko b chla jaye doesnt matter
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                cnt++;
                ans[i]=cnt%2;
            }
            else {
                ans[i]=cnt%2;
                cnt--;
            }
            
        }
        return ans;
    }
};