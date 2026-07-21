class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        int activeCount = count(begin(s), end(s), '1');

        vector<int> inactive;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                inactive.push_back(i - start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;
        for (i = 1; i < inactive.size(); i++) {
            maxPairSum = max(maxPairSum, inactive[i] + inactive[i - 1]);
        }

        return maxPairSum + activeCount;
    }
};
