class Solution:
    def fun(self, i, amt, coins, dp):

        if amt == 0:
            return 0

        if i == len(coins) or amt < 0:
            return float('inf')

        if dp[i][amt] != -1:
            return dp[i][amt]

        take = 1 + self.fun(i, amt - coins[i], coins, dp)

        nottake = self.fun(i + 1, amt, coins, dp)

        dp[i][amt] = min(take, nottake)

        return dp[i][amt]

    def coinChange(self, coins: List[int], amount: int) -> int:

        n = len(coins)
      
        dp = [[-1] * (amount + 1) for _ in range(n)]

        ans = self.fun(0, amount, coins, dp)

        if ans == float('inf'):
            return -1

        return ans

