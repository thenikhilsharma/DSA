class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if (s.length() == 0){
            return 0;
        }
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return check(s, s2);
    }
    int check(string &text1, string &text2){
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};