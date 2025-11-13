class Solution {
public:
    int maxOperations(string s) {
        int n=s.length();
        int one=0; //no of ones seen ab tk
        //to jitne zero milenge itne one ko utna travel krna pdega
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                while((i+1)<n && s[i+1]=='0') i++;
            
            ans+=one;}
            else one++;
        }
        return ans;
    }
};