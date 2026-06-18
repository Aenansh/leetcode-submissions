class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = 30.0 * (double)(hour);
        double min = 5.5 * (double)(minutes);

        double a1 = abs(hr - min);
        double a2 = abs(360.0 - a1);
        return a1 < a2 ? a1 : a2;
    }
};
