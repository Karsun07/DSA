class Solution:
    def fun(self, i, n, dp):
        if i > n:
            return 0

        if i == n:
            return 1

        if dp[i] != -1:
            return dp[i]

        one = self.fun(i + 1, n, dp)
        two = self.fun(i + 2, n, dp)

        dp[i] = one + two
        return dp[i]

    def climbStairs(self, n: int) -> int:
        dp = [-1] * (n + 2)

        return self.fun(0, n, dp)

