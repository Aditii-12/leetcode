class Solution {
public:
long long mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nle(n), ple(n);
        int sum=0;
        stack<int> st;
         for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ple[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
         for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            nle[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            sum = (sum + arr[i] * left * right) % mod;
        }
        return sum;
    }
};