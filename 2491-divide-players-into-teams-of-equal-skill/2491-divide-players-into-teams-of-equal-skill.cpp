class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(),skills.end());
        int n=skills.size();
        int i=0;
        int j=n-1;
        long long ans=0;
        int temp=-1;
        while(i<j){
            if(temp==-1) temp=skills[i]+skills[j];
            if(skills[i]+skills[j]!=temp) return -1;
            else ans+=(skills[i]*skills[j]);
            i++;
            j--;
        }
        return ans;
    }
};