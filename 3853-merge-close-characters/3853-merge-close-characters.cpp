class Solution {
public:
    string mergeCharacters(string s, int ki) {
        string t=s;
        for(int i=0;i<100;i++){ //max 100 merge can happen
            bool f=0;
            for(int j=0;j<t.size();j++){
                for(int k=j+1;k<t.size();k++){
                    if(t[j]==t[k] && (k-j)<=ki){
                        t.erase(k,1); //removes the right wala char
                        f=1; //kyuki sbse left wale se hi merge krna h bs
                        break;
                    }
                }
                if(f) break;
            }
            if(!f) break; //no merge so ab khtm we can return
        }
        return t;
    }
};