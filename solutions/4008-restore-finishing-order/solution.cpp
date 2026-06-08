class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size(), m = friends.size();
        unordered_map<int, bool> isFriend;

        for (int f : friends)
            isFriend[f] = true;
        
        int idx = 0;
        for(int i = 0; i < n; i++) {
            int pos = order[i];
            if(isFriend[pos]) {
                friends[idx] = pos;
                idx++;
            }
        }
        return friends;
    }
};
