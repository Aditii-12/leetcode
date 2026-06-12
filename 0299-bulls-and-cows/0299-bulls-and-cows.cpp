class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> m,n;
        int bulls=0;
        int cows=0;
        int i=0;
        while(i<secret.size()){
            if(secret[i]==guess[i]){
                bulls++;
                secret.erase(secret.begin() + i);
                guess.erase(guess.begin() + i);
            }
            else{
                    m[secret[i]]++;
                    n[guess[i]]++;
                    i++;
            }
        }
        for(auto x : m){
            cows += min(x.second,n[x.first]);
        }

        string ans = "";
        ans += to_string(bulls)+"A";
        ans += to_string(cows)+"B";
        return ans;
    }
};