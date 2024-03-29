int Solution::isScramble(string A, string B) {
    int length1 = A.length();
    if (length1 != B.length()) return false;
    if (A == B) return true;

    bool dp[length1][length1][length1];
    for (int i = 0; i < length1; ++i) {
        for (int j = 0; j < length1; ++j) {
            dp[i][j][0] = (A[i] == B[j]);
        }
    }

    for (int k = 1; k < length1; ++k) {
        for (int i = 0; i < length1 - k; ++i) {
            for (int j = 0; j < length1 - k; ++j) {
                dp[i][j][k] = false;
                for (int p = 0; p < k; ++p) {
                    if ((dp[i][j][p] && dp[i + p + 1][j + p + 1][k - p - 1])
                        || (dp[i][j + k - p][p] && dp[i + p + 1][j][k - p - 1])) {
                        dp[i][j][k] = true;
                        break;
                    }
                }
            }
        }
    }
    return dp[0][0][length1 - 1];
}
