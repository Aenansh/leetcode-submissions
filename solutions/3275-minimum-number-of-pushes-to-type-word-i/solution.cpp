class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        int pushes = 0;

        for (char letter : word) {
            cnt++;
            pushes += cnt < 9 ? 1 : (cnt < 17 ? 2 : (cnt < 25 ? 3 : 4));
        }

        return pushes;
    }
};
