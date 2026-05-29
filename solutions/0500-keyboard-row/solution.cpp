unordered_set<char> r1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                          'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};

unordered_set<char> r2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
                          'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};

unordered_set<char> r3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm',
                          'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;

        for (auto s : words) {
            int row = r1.count(s[0]) ? 1 : (r2.count(s[0]) ? 2 : 3);
            bool insertIt = true;
            for (int i = 1; i < s.length(); i++) {
                int row_c = r1.count(s[i]) ? 1 : (r2.count(s[i]) ? 2 : 3);
                if (row_c != row)
                    insertIt = false;
            }
            if (insertIt)
                ans.push_back(s);
        }
        return ans;
    }
};
