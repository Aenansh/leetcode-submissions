class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ranks(n, "");

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        int remains = 0;
        while (!pq.empty()) {
            auto [s, r] = pq.top();
            pq.pop();

            if (remains == 0) {
                ranks[r] = "Gold Medal";
            } else if (remains == 1) {
                ranks[r] = "Silver Medal";
            } else if (remains == 2) {
                ranks[r] = "Bronze Medal";
            } else {
                ranks[r] = to_string(remains + 1);
            }
            remains++;
        }
        return ranks;
    }
};
