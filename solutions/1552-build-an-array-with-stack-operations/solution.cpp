class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> oper;
        for (int i = 1; i <= target[target.size() - 1]; i++) {
            oper.push_back("Push");
            if (find(target.begin(), target.end(), i) == target.end())
                oper.push_back("Pop");
            // else
            //     oper.push_back("Push");
        }
        return oper;
    }
};
