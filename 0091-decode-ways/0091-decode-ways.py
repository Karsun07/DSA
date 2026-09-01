class Solution:
    def fun(self, i, s, dp):
        n = len(s)

        if i == n:
            return 1

        if s[i] == '0':
            return 0

        if dp[i] != -1:
            return dp[i]

        ways = self.fun(i+1, s, dp)

        if i+1 < n and 10 <= int(s[i:i+2]) <= 26:
            ways += self.fun(i+2, s, dp)

        dp[i] = ways

        return dp[i]


    def numDecodings(self, s: str) -> int:
        n = len(s)

        dp = [-1] * n

        return self.fun(0, s, dp)