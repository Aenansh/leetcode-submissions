class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;

        vector<int> res;

        for (int i = 0; i < n; i++) {
            int num = arr[i];
            int d = abs(x - num);
            if (pq.size() == k) {
                if (d < pq.top().first) {
                    pq.pop();
                    pq.push({d, num});
                } else if (d == pq.top().first) {
                    if (num < pq.top().second) {
                        pq.pop();
                        pq.push({d, num});
                    }
                } else
                    break;
            } else
                pq.push({d, num});
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        sort(begin(res), end(res));

        return res;
    }
};
