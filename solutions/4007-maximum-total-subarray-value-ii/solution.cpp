class SegmentTree {
public:
    vector<int> tree;
    bool isMinTree;

    SegmentTree(vector<int> nums, bool isMin) {
        isMinTree = isMin;
        int n = nums.size();
        tree.resize(4 * n);
        buildTree(0, 0, n - 1, nums);
    }
    void buildTree(int i, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[i] = arr[r];
            return;
        }

        int m = l + (r - l) / 2;
        buildTree(2 * i + 1, l, m, arr);
        buildTree(2 * i + 2, m + 1, r, arr);
        if (isMinTree)
            tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
        else tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
    int querySegmentTree(int start, int end, int i, int l, int r) {
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        if (l >= start && r <= end) {
            return tree[i];
        }

        int mid = l + (r - l) / 2;
        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        return isMinTree ? min(a, b) : max(a, b);
    }
    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};

class Solution {
    long long getValue(int l, int r, SegmentTree& minTree,
                       SegmentTree& maxTree, int n) {
        int minEl = minTree.query(l, r, n);
        int maxEl = maxTree.query(l, r, n);

        return (long long)maxEl - minEl;
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minTree(nums, true);
        SegmentTree maxTree(nums, false);

        priority_queue<tuple<long long, int, int>> pq;
        for (int l = 0; l < n; l++) {
            long long val = getValue(l, n - 1, minTree, maxTree, n);
            pq.push({val, l, n - 1});
        }

        long long res = 0;
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();
            res += value;

            long long nextBest = getValue(l, r - 1, minTree, maxTree, n);
            pq.push({nextBest, l, r - 1});
        }

        return res;
    }
};
