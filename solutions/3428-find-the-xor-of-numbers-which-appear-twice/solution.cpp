class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> freq;
        for(auto i : nums){
            if(freq[i]){
                ans ^= i;
            }
            else{
                freq[i]++;
            }
        } 
        return ans;
    }
};
