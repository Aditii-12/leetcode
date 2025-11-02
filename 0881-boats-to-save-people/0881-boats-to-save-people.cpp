class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<=j){
            if(people[i]+people[j]<=limit){
                i++; //ek aage se and ek piche se
                j--;
                ans++;
            }
            else{
                j--; //agr sbse aage wala match ni hua to koi ni hoga
                //to akele hi jana pdega
                ans++;
            }
        }
        return ans;
    }
};