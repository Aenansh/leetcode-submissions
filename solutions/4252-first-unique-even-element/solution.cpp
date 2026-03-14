class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> fq;
        for (int i : nums) {
            fq[i]++;
        }
        for (int i : nums) {
            if (i % 2 == 0 && fq[i] == 1)
                return i;
        }
        return -1;
    }
};
