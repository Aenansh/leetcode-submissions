class Solution {
    bool is_good(int x) {
        if (x < 10) return true; // Single digits are automatically good
        
        string s = to_string(x);
        bool inc = true, dec = true;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] <= s[i-1]) inc = false; // Broke strict increasing rule
            if (s[i] >= s[i-1]) dec = false; // Broke strict decreasing rule
        }
        
        return inc || dec;
    }

    string S;
    
    // DP Memoization table
    // [index][started][last_digit][monotone_state][digit_sum]
    long long memo[20][2][11][4][145];

    long long dfs(int idx, bool tight, bool started, int last_d, int m_state, int sum_d) {
        // Base case: We've built the whole number
        if (idx == S.length()) {
            if (!started) return 1; // 0 is technically fancy
            
            // It is fancy if the number itself is good OR the digit sum is good
            if (m_state != 3 || is_good(sum_d)) return 1;
            return 0;
        }

        // Return memoized result if we've been in this exact unconstrained state before
        if (!tight && memo[idx][started][last_d][m_state][sum_d] != -1) {
            return memo[idx][started][last_d][m_state][sum_d];
        }

        long long ans = 0;
        // If 'tight' is true, we are bound by the prefix of our target number
        int limit = tight ? (S[idx] - '0') : 9;

        for (int d = 0; d <= limit; d++) {
            bool new_tight = tight && (d == limit);
            bool new_started = started || (d > 0);
            int new_sum = sum_d + d;
            int new_last = last_d;
            int new_m_state = m_state;

            if (!started) {
                if (d > 0) {
                    new_last = d;      // Record our very first digit
                    new_m_state = 0;   // Still uninitialized
                } else {
                    new_last = 10;     // Placeholder for "no digit placed yet"
                    new_m_state = 0;
                }
            } else {
                new_last = d;
                
                // Progress the monotone state machine
                if (m_state == 0) {
                    if (d > last_d) new_m_state = 1;      // Transition to strictly increasing
                    else if (d < last_d) new_m_state = 2; // Transition to strictly decreasing
                    else new_m_state = 3;                 // Flat line -> Invalid
                } else if (m_state == 1) {
                    if (d > last_d) new_m_state = 1;
                    else new_m_state = 3;
                } else if (m_state == 2) {
                    if (d < last_d) new_m_state = 2;
                    else new_m_state = 3;
                } else {
                    new_m_state = 3; // Once broken, stays broken
                }
            }

            ans += dfs(idx + 1, new_tight, new_started, new_last, new_m_state, new_sum);
        }

        if (!tight) memo[idx][started][last_d][m_state][sum_d] = ans;
        return ans;
    }

    long long solve_count(long long x) {
        if (x < 0) return 0;
        S = to_string(x);
        memset(memo, -1, sizeof(memo));
        return dfs(0, true, false, 10, 0, 0); // Start DFS with no digits placed
    }
public:
    long long countFancy(long long l, long long r) {
        pair<long long, long long> morvaxelin = {l, r};
        
        // Count valid numbers from 0 to R, minus valid numbers from 0 to L-1
        return solve_count(morvaxelin.second) - solve_count(morvaxelin.first - 1);
    }
};
