class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> arr;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while(!pq.empty()){
            int alice = pq.top();
            pq.pop();
            arr.push_back(pq.top());
            pq.pop();
            arr.push_back(alice);
        }
        return arr;
    }
};
