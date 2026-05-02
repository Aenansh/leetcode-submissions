class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people), end(people), greater<int>());
        int n = people.size();
        int boats = 0;
        int L = 0, R = n - 1;

        while (L <= R) {
            int wg = limit - people[L];
            if (L < R && wg >= people[R])
                R--;
            boats++, L++;
        }
        return boats;
    }
};
