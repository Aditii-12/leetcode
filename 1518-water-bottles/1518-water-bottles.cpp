class Solution {
public:
    int numWaterBottles(int nb, int ne) {
    int c= 0;

        while (nb >= ne) {
            c += ne;
            nb -= ne;

            nb++;
        }

        return c+nb;
    }
};