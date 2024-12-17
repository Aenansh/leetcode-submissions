class Solution {
public:
    int maxProduct(vector<int>& nums) {
        make_heap(nums.begin(), nums.end());
        int first = nums.front();
        pop_heap(nums.begin(), nums.end());
        return (nums.front() - 1) * (first - 1);
    }
};
