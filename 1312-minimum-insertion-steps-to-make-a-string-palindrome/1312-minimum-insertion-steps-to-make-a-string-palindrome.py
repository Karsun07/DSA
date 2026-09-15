class Solution:

    def fun(self, i, j, s, dp):

        if i >= j:
            return 0

        if dp[i][j] != -1:
            return dp[i][j]

        if s[i] == s[j]:
            dp[i][j] = self.fun(i + 1, j - 1, s, dp)
        else:
            dp[i][j] = 1 + min(
                self.fun(i + 1, j, s, dp),
                self.fun(i, j - 1, s, dp)
            )

        return dp[i][j]

    def minInsertions(self, s: str) -> int:
        n = len(s)

        dp = [[-1] * n for _ in range(n)]

        return self.fun(0, n - 1, s, dp)