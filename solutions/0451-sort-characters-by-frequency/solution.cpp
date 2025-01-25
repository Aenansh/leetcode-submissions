class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        for (auto i : mp) {
            pq.push(make_pair(i.second, i.first));
        }
        s = "";
        while (!pq.empty()) {
            if (mp[pq.top().second]) {
                s += pq.top().second;
                mp[pq.top().second]--;
            } else
                pq.pop();
        }
        return s;
    }
};
