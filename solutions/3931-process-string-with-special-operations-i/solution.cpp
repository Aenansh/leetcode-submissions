class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (char c : s) {
            if (c == '*') {
                if (!result.empty())
                    result.pop_back();
            } else if (c == '#')
                result += result;
            else if (c == '%')
                reverse(begin(result), end(result));
            else
                result.push_back(c);
        }
        return result;
    }
};
