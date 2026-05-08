class Solution {
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);
        unordered_map<int, vector<int>> primeToIndices;
        vector<vector<int>> factorsOf(n);
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            if (temp < 2) continue;
            for (int d = 2; d * d <= temp; d++) {
                if (temp % d == 0) {
                    primeToIndices[d].push_back(i);
                    factorsOf[i].push_back(d);
                    while (temp % d == 0) temp /= d;
                }
            }
            if (temp > 1) {
                primeToIndices[temp].push_back(i);
                factorsOf[i].push_back(temp);
            }
        }

        queue<pair<int, int>> q;
        vector<bool> visited(n, false);
        unordered_set<int> visitedPrimes;

        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();
            for (int nextIdx : {curr - 1, curr + 1}) {
                if (nextIdx >= 0 && nextIdx < n && !visited[nextIdx]) {
                    if (nextIdx == n - 1) return dist + 1;
                    visited[nextIdx] = true;
                    q.push({nextIdx, dist + 1});
                }
            }
            int val = nums[curr];
            if (isPrime(val)) {
                if (visitedPrimes.find(val) == visitedPrimes.end()) {
                    for (int targetIdx : primeToIndices[val]) {
                        if (!visited[targetIdx]) {
                            if (targetIdx == n - 1) return dist + 1;
                            visited[targetIdx] = true;
                            q.push({targetIdx, dist + 1});
                        }
                    }
                    visitedPrimes.insert(val);
                    primeToIndices.erase(val);
                }
            }
        }

        return -1;
    }
};
