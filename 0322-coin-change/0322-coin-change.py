class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        n = len(coins)

        dp = [[float('inf')] * (amount + 1) for _ in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 0

        for i in range(n - 1, -1, -1):

            for amt in range(1, amount + 1):

                nottake = dp[i + 1][amt]

                take = float('inf')

                if coins[i] <= amt:
                    take = 1 + dp[i][amt - coins[i]]

                dp[i][amt] = min(take, nottake)

        ans = dp[0][amount]

        if ans == float('inf'):
            return -1

        return ans

