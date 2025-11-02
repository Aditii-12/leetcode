class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int maxi=0;
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0;int j=n-1;
        //hm starting se faceup kre ya end se - score will be increased by 1 only
        //so we try ki hm age se kre(w smaller values) 
        //and last se face down to regain more and more power
        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxi=max(maxi,score);
                power-=tokens[i];
                i++;
            }
            else if(score>0){
                power+=tokens[j];
                j--;
                score--;
            }
            else break; //when score==0,we cant make any move further
        }
        return maxi;
    }
};