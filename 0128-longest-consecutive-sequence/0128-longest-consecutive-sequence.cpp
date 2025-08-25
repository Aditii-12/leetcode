class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int maxlen=0;
        for(int num:s){
            if(s.find(num-1)==s.end()) //usse ek kam ni mila
            {
                int current=num;
                int count=1; //start counting again
            //now just count age ke integers and increase the count
            while(s.find(current+1)!=s.end()){//consecutive integers milrhe h
            count++;
            current++;
            }
            maxlen=max(maxlen,count);
            }
        }
        return maxlen;

    }
};