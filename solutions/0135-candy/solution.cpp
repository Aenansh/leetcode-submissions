class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<long long> dist(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1] && dist[i - 1] >= dist[i])
                dist[i] = 1 + max(dist[i], dist[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && dist[i + 1] >= dist[i])
                dist[i] = 1 + max(dist[i], dist[i + 1]);
        }
        return (long long)accumulate(begin(dist), end(dist), 0);
    }
};
