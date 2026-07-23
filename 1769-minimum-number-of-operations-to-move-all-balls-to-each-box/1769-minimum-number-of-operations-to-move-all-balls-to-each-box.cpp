class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        int balls=0;
        int moves=0;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]+=moves;
            if(boxes[i]=='1') balls++;
            moves+=balls;
        }
        balls=0;
        moves=0;
        for(int i=n-1;i>=0;i--){
            ans[i]+=moves;
            if(boxes[i]=='1') balls++;
            moves+=balls;
        }
        return ans;
    }
};