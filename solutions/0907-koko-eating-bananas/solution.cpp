class Solution {
    bool canEat(vector<int>& piles, int c, int h) {
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++) {
            hours += (piles[i] % c == 0) ? (piles[i] / c) : (piles[i] / c) + 1;
        }
        return hours <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = *max_element(begin(piles), end(piles));
        int n = piles.size();
        if(n == h) return maxpile;
        int l = 1, r = maxpile;
        int ans = maxpile;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canEat(piles, mid, h)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};
