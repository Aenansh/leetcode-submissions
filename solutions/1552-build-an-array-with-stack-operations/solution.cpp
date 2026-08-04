class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        unordered_map<int, bool> mp;

        for (auto t : target)
            mp[t] = true;

        stack<int> s;
        int idx = 0, i = 1;
        int ts = target.size();

        while (i <= n && idx < ts) {
            if (mp[i]) {
                idx++;
                while (!s.empty() && !mp[s.top()]) {
                    s.pop();
                    ans.push_back("Pop");
                }
            }
            s.push(i++);
            ans.push_back("Push");
        }

        return ans;
    }
};
