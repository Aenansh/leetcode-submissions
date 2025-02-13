class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        if(nums.size() < 2) return 0;
        int ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto i : nums){
            pq.push(i);
        }
        while(pq.top() < k){
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long z = min(x, y) * 2 + max(x, y);
            pq.push(z); 
            ans++;
        }
        return ans;
    }
};
