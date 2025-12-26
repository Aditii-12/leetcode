class Solution {
public:
    int bestClosingTime(string customers) {
        int n= customers.size();
        int tot=0;
        for (int i=0;i<n;i++) {
            if (customers[i] == 'Y') {
                tot++;
            }
        }
        int mini = tot;
        int ans = 0;

        for (int i=0;i<n;i++) {
            char ch = customers[i];
            if (ch == 'Y') {
                tot--;
            } else {
                tot++;
            }

            if (tot < mini) {
                ans= i + 1;
                mini =tot;
            }
        }

        return ans;
    }
};