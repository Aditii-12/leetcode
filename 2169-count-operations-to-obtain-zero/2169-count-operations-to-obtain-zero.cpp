class Solution {
public:
    int countOperations(int num1, int num2) {
        int i = 0;
        while (num1 > 0 && num2 > 0) { // Ensure neither number becomes zero
            if (num1 >= num2) num1 -= num2;
            else num2 -= num1;
            i++;
        }
        return i;
    }
};
