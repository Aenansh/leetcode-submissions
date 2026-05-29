class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();

        unordered_set<int> freq;
        for (int candy : candyType) {
            if (!freq.count(candy))
                freq.insert(candy);
        }

        int candies = freq.size();

        return min(candies, n / 2);
    }
};
