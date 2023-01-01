class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        int r, c;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                r = j;
                c = j + i;
                if(c == n) break;
                if(s[r] == s[c]) {
                    dp[r][c] = dp[r+1][c-1];
                }else {
                    dp[r][c] = 1 + min(dp[r+1][c], dp[r][c-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
