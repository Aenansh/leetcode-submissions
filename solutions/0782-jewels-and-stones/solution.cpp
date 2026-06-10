class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool> mp;
        for(char j : jewels) {
            mp[j] = true;
        }

        int js = 0;
        for(char c : stones) {
            if(mp[c]) js++;
        }
        return js;
    }
};
