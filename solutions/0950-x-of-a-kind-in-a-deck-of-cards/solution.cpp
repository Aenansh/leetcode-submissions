class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (auto d : deck)
            mp[d]++;

        int g = 0;
        for(auto [k, v] : mp) {
            g = gcd(g, v);
        }

        return g >= 2;
    }
};
