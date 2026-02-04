class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int maxArea = 0;

        while(low <= high) {
            int w = high - low;
            int h = min(height[low], height[high]);
            maxArea = max(maxArea, w * h);
            height[low] < height[high] ? low++ : high--;
        }
        return maxArea;
    }
};
