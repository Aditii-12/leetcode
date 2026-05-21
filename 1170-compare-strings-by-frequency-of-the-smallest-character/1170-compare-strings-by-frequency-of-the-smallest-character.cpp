class Solution {
public:
     int freq(string s)
    {
        char sm='z'; //abi ke liye we take this as smallest and then compare krke change kdenge
        int cnt=0;
        for(char c : s)
        {
            if(c<sm)
            {
                sm=c;
                cnt=1;
            }
            else if(c==sm)
            {
                cnt++;
            }
        }

        return cnt;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>ans;
        vector<int>wf; //word freq store krlenge fir usse compare krte rhenge for queries
        for(string w:words){
            wf.push_back(freq(w));
        }
        sort(wf.begin(),wf.end());
        for(string q:queries){
            int f=freq(q);
            auto it=upper_bound(wf.begin(),wf.end(),f);
            ans.push_back(wf.end()-it); //how many elements greater than freq of queries
        }
        return ans;
    }
};