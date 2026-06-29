class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>l;
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(l.count(cards[i])){
                ans=min(ans,i-l[cards[i]]+1);
            }
            l[cards[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};