class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto i : nums){
            freq[i]++;
        }
        priority_queue<vector<int>> pq;
        for(auto i : freq){
            vector<int> com = {i.second, i.first};
            pq.push(com);
        }
        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(pq.top()[1]);
            pq.pop();
        }
        return res;
    }
};
