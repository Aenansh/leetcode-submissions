class Solution {
public:
    int minimumChairs(string s) {
        int people = 0, chairs = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E') {
                people++;
                if (people > chairs)
                    chairs++;
            } else {
                people--;
            }
        }

        return chairs;
    }
};
