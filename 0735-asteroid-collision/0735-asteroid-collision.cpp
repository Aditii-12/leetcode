class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool f=0;
            
            while (!st.empty() && a<0 && st.top()>0) { 
                if (abs(st.top())>abs(a)){  
                    f=1;
                    break;
                } else if (abs(st.top())==abs(a)) { 
                    st.pop();
                    f=1;
                    break;
                } else { 
                    st.pop();
                }
            }
            
            if (!f) st.push(a);
        }
        vector<int> result(st.size());
        for (int i = st.size()-1;i>=0;i--) {
            result[i]=st.top();
            st.pop();
        }
        return result;
    }
};