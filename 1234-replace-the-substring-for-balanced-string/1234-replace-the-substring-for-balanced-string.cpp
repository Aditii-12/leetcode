class Solution {
public:
//isme we will see ki letters kitni br extra h
//then we will fix them for the letters that are missing
    int balancedString(string s) {
        int n=s.length();
        int need=n/4;
        unordered_map<char,int>freq;
        for(char it:s){
            freq[it]++;
        }
        if(freq['Q']==need && freq['W']==need && freq['E']==need && freq['R']==need){
            return 0;
        }
    //now in freq we will maintain window ke bhr ki freq
        int ans=n; //worst case
        int l=0;
        int r=0;
        while(r<n){
            freq[s[r]]--;
            //checking if ourside widnow is valid
            //vo kese valid hogi jb usme sbki freq <=need
            //to window ki length lelenge min krke
            while (l <= r && freq['Q']<=need && freq['W']<=need &&
                   freq['E']<=need && freq['R']<=need) 
            {
                ans = min(ans,r-l+1);
                freq[s[l]]++;   
                l++;
            }

        r++;
        }
        return ans;
        
    }
};