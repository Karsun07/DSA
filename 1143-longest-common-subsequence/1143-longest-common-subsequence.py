class Solution:
    def fun(self, i, j, text1, text2,dp):

        if i == len(text1) or j == len(text2):
            return 0
        if dp[i][j]!=-1 :
            return dp[i][j]
        
        if text1[i] == text2[j]:
            dp[i][j]= 1 + self.fun(i + 1, j + 1, text1, text2,dp)
            return dp[i][j]

        else:
            dp[i][j]=max(
                self.fun(i + 1, j, text1, text2,dp),
                self.fun(i, j + 1, text1, text2,dp)
            )
            return dp[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        r=len(text1)
        c=len(text2)

        dp=[[-1]*(c+1) for _ in range(r+1)]

        # return self.fun(0, 0, text1, text2,dp)
        
        for i in range(r):
            dp[i][c]=0

        for j in range(c):
            dp[r][j]=0

        for i in range(r-1,-1,-1):
            for j in range(c-1,-1,-1):

                if text1[i] == text2[j]:

                    dp[i][j]= 1 + self.fun(i + 1, j + 1, text1, text2,dp)
                

                else:
                    dp[i][j]=max(
                    self.fun(i + 1, j, text1, text2,dp),
                    self.fun(i, j + 1, text1, text2,dp)
                    )
        return dp[0][0]
                    


