class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        while(a>0 || b>0){
            if(res.size()>=2 && res.back()==res[res.size()-2]){
                if(res.back()=='a') {
                    res+='b'; b--;
                }
                else{
                    res+='a'; a--;
                }
            }
            else{
                if(a>b){
                    res+='a';
                    a--;
                }
                else{
                    res+='b';
                    b--;
                }
            }
        }
        return res;
    }
};