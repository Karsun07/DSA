class Solution:
    def fun(self, start, s, wordDict,dp):
        if start == len(s):
            return True
        if dp[start]!=-1 :
            return dp[start]

        for i in range(start, len(s)):
            x = s[start:i+1]

            if x in wordDict:
                if self.fun(i+1, s, wordDict,dp):
                    dp[i]=True
                    return dp[i]

        dp[start]=False
        return dp[start]


    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        st = set(wordDict)
        dp=[-1]*(len(s)+1)

        return self.fun(0, s, st,dp)