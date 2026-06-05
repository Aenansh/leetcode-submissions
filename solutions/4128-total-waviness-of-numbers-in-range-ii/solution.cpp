class Solution {
    string s;
    int n;

    long long dpTotalNumbers[16][10][10];
    long long dpTotalWaviness[16][10][10];

    pair<long long, long long> calc(int curr, int prevPrev, int prev,
                                    bool isLimited, bool isLeading) {
        if (curr >= n) {
            return {1, 0};
        }

        if (!isLimited && !isLeading && prevPrev >= 0 && prev >= 0) {
            if (dpTotalNumbers[curr][prevPrev][prev] != -1 &&
                dpTotalWaviness[curr][prevPrev][prev]) {
                return {
                    dpTotalNumbers[curr][prevPrev][prev],
                        dpTotalWaviness[curr][prevPrev][prev]
                };
            }
        }

        long long totalNumbers = 0;
        long long totalWaveScore = 0;

        int limited = isLimited ? (s[curr] - '0') : 9;

        for (int d = 0; d <= limited; d++) {
            bool newLeading = isLeading && (d == 0);
            int newPrevPrev = prev;
            int newPrev = newLeading ? -1 : d;

            auto [remainTotalNumbers, remainTotalWaveScore] =
                calc(curr + 1, newPrevPrev, newPrev,
                     (isLimited && d == limited), newLeading);

            if (!newLeading && prevPrev >= 0 && prev >= 0) {
                bool isPeak = (prevPrev < prev && prev > d);
                bool isValley = (prevPrev > prev && prev < d);

                if (isPeak || isValley) {
                    totalWaveScore += remainTotalNumbers;
                }
            }
            totalNumbers += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }

        if (!isLimited && !isLeading && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev] = totalNumbers;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }
        return {totalNumbers, totalWaveScore};
    }

    long long solve(long long num) {
        if (num < 100)
            return 0;

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = calc(0, -1, -1, true, true);

        return totalWaveScore;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};
