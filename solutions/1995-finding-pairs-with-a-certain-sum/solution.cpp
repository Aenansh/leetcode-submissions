class FindSumPairs {
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> table;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto i : this->nums2) {
            this->table[i]++;
        }
    }

    void add(int index, int val) {
        int old = nums2.at(index);
        nums2.at(index) += val;
        table[nums2.at(index)]++;
        table[old]--;
        if (table[old] == 0)
            table.erase(old);
    }

    int count(int tot) {
        int count = 0;
        for (auto i : nums1) {
            if (table[tot - i]) {
                count += table[tot - i];
            }
        }

        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
