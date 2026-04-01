class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = positions.size();
        stack<int> s;
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(),
             [&](int a, int b) { return positions[a] < positions[b]; });

        for (auto& id : ids) {
            if (directions[id] == 'R') {
                s.push(id);
            } else {
                while (!s.empty() && healths[id] > 0) {
                    int top_id = s.top();
                    if (healths[top_id] < healths[id]) {
                        healths[top_id] = 0;
                        healths[id] -= 1;
                        s.pop();
                    } else if (healths[id] < healths[top_id]) {
                        healths[id] = 0;
                        healths[top_id] -= 1;
                        break;
                    } else {
                        healths[id] = 0;
                        healths[top_id] = 0;
                        s.pop();
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0)
                ans.push_back(healths[i]);
        }
        return ans;
    }
};
