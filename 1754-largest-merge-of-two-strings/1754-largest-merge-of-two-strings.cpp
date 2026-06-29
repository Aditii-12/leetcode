class Solution {
public:
    string largestMerge(string w1, string w2) {
        int i=0;
        int j=0;
        string ans="";
        while(i<w1.size() && j<w2.size()){
            if(w1[i]>w2[j]){
                ans+=w1[i];
                i++;
            }
            else if(w1[i]<w2[j]){
                ans+=w2[j];
                j++;
            }
            else{
                string s=w1.substr(i);
                string t=w2.substr(j);
                if(s>t){
                    ans+=w1[i++];
                }
                else{
                    ans+=w2[j++];
                }
            }
        }
        while(i<w1.size()){
            ans+=w1[i++];
        }
        while(j<w2.size()){
            ans+=w2[j++];
        }
        return ans;
    }
};