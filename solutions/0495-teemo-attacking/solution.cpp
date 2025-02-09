class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int dur = duration;
        for(int i = 0; i < timeSeries.size() - 1; i++){
            int n = timeSeries[i + 1] - timeSeries[i];
            if(n >= duration) dur += duration;
            // else if(n == duration) dur += duration - 1;
            else dur += n;
        }
        return dur;
    }
};
