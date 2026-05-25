class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1')
            return false;
        
        queue<int> q;
        q.push(0);

        int far = 0;
        while(!q.empty()) {
            int c = q.front();
            q.pop();
            
            if(c == n - 1) return true;
            
            int start = max(c + minJump, far + 1);
            int end = min(c + maxJump, n - 1);

            for(int i = start; i <= end; i++) {
                if(s[i] == '0') q.push(i);
            }

            far = max(far, end);
        }
        return false;
    }
};
