class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for(int i = 0; i < k; i++){
            make_heap(gifts.begin(), gifts.end());
            int s = sqrt(gifts.front());
            gifts.front() = s;
        }
        long long sum = 0;
        for(int i = 0; i < gifts.size(); i++){
            sum += gifts[i];
        }
        return sum;
    }
};
