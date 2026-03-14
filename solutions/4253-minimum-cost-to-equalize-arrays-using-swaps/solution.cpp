class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> total_count;
        unordered_map<int, int> nums1_count;

        for(int i = 0; i < nums1.size(); i++) {
            total_count[nums1[i]]++;
            total_count[nums2[i]]++;

            nums1_count[nums1[i]]++;
        }

        for(auto const& [val, count] : total_count) {
            if(count % 2 != 0) return -1;
        }

        int min_swaps = 0;
        for(auto const& [val, count1] : nums1_count) {
            int target_amount = total_count[val] / 2;

            if(count1 > target_amount) {
                min_swaps += (count1 - target_amount);
            }
        }

        return min_swaps;
    }
};
