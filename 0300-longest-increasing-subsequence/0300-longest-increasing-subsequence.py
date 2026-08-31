class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)

        
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):

            for prev in range(-1, i):

                nottake = dp[i + 1][prev + 1]

                take = 0

                if prev == -1 or nums[i] > nums[prev]:
                    take = 1 + dp[i + 1][i + 1]

                dp[i][prev + 1] = max(take, nottake)

        return dp[0][0]

