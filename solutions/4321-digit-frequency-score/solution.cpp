class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> dFreq;
        while(n > 0) {
            dFreq[n % 10]++;
            n = n / 10;
        }
        
        int score = 0;
        for(auto [k, v] : dFreq) {
            score += k * v;
        }
        return score;
    }
};
