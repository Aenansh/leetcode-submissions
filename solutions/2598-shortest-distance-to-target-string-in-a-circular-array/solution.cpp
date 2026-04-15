class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        if (words[startIndex] == target)
            return 0;
        int n = words.size();

        // loop right
        int minDisR = INT_MAX;
        int ir = (startIndex + 1) % n;
        int dis = 1;
        while (ir != startIndex) {
            if (words[ir] == target) {
                minDisR = dis;
                break;
            }
            ir = (ir + 1) % n;
            dis++;
        }

        // loop left
        int minDisL = INT_MAX;
        int il = (startIndex - 1 + n) % n;
        dis = 1;
        while (il != startIndex) {
            if (words[il] == target) {
                minDisL = dis;
                break;
            }
            il = (il - 1 + n) % n;
            dis++;
        }

        return min(minDisR, minDisL) != INT_MAX ? min(minDisR, minDisL) : -1;
    }
};
