class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long bigmass = (long long)mass;
        sort(begin(asteroids), end(asteroids));

        for (int m : asteroids) {
            if (bigmass < m)
                return false;
            bigmass = bigmass + (long long)m;
        }
        return true;
    }
};
