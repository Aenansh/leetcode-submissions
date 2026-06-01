class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        unordered_set<long long> visited;

        pq.push(1);
        visited.insert(1);

        long long curr = 1;

        for(int i = 0; i < n; i++) {
            curr = pq.top();
            pq.pop();

            long long muls[3] = {2 * curr, 3 * curr, 5 * curr};
            for(auto mul : muls) {
                if(!visited.count(mul)) {
                    visited.insert(mul);
                    pq.push(mul);
                }
            }
        }
        return curr;
    }
};
