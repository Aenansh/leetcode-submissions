void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r,
                     int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(
        querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
        querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s,
                                            vector<vector<int>>& queries) {
        int n = s.length();

        int activeCount = count(begin(s), end(s), '1');

        vector<int> startBlock;
        vector<int> endBlock;
        vector<int> size;

        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0')
                    i++;
                startBlock.push_back(start);
                endBlock.push_back(i - 1);
                size.push_back(i - start);
            } else
                i++;
        }

        if (startBlock.size() < 2) {
            return vector<int>(queries.size(), activeCount);
        }

        int N = size.size() - 1;
        vector<int> pairSum(N);

        for (int i = 0; i < N; i++) {
            pairSum[i] = size[i + 1] + size[i];
        }

        int* st = constructST(pairSum.data(), N);

        vector<int> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];

            int low = lower_bound(begin(endBlock), end(endBlock), l) -
                      begin(endBlock);
            int high = upper_bound(begin(startBlock), end(startBlock), r) -
                       begin(startBlock) - 1;

            int maxPairSum = 0;
            if (low < high) {
                int fLen = endBlock[low] - max(startBlock[low], l) + 1;
                int lLen = min(endBlock[high], r) - startBlock[high] + 1;

                if (high - low == 1) {
                    maxPairSum = fLen + lLen;
                } else {
                    int p1 = fLen + size[low + 1];
                    int p2 = size[high - 1] + lLen;
                    int rmq = RMQ(st, N, low + 1, high - 2);
                    maxPairSum = max({p1, p2, rmq});
                }
            }
                res.push_back(maxPairSum + activeCount);
        }
        return res;
    }
};
