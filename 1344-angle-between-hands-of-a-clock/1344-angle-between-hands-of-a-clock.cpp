class Solution {
public:
    double angleClock(int hour, int minutes) {
        double houra=hour*30.0+minutes * 0.5;
        double mina=minutes*6.0;

        double diff=abs(houra-mina);
        return min(diff,360.0-diff);
    }
};